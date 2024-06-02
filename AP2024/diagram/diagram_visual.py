import matplotlib.pyplot as plt
import numpy as np
import mplcyberpunk
import json

from .diagram_object import SortParam, D
from .config_diagram import name_mode, ylabel_mode
from ..measurement import mode_sort


class Diagram:
    sort_m: dict
    LOG_C: int = 100

    def __init__(self, param: SortParam, *args, one_diagram=True, draw_log=False):
        plt.style.use("cyberpunk")
        self.param = param

        for sort_m in args:
            if not isinstance(sort_m, D):
                continue
            self.plot_sort(_sort=sort_m)

            if draw_log and not one_diagram:
                self._draw_log()

            if not one_diagram:
                self._show_plot()

        if one_diagram:
            if draw_log:
                self._draw_log()
            self._show_plot()

    def _draw_log(self):
        plt.draw()

        self._load("PyIntroSort")
        n_elements = np.array(self.sort_m["count"])

        n_elements_normalized = n_elements / max(n_elements) * self.LOG_C
        y_min, y_max = plt.ylim()

        n_log_n = n_elements_normalized * np.log(n_elements_normalized)

        max_n_log_n = np.max(n_log_n)
        n_log_n_normalized = (n_log_n / max_n_log_n) * y_max

        plt.plot(n_elements, n_log_n_normalized, 'r--', label='O(n log n)')

    def plot_sort(self, _sort: D):
        if _sort.mode == "all":
            for sort_now in _sort.sort_algo:
                self._load(sort_now.__name__)
                for mode in mode_sort:
                    self._plot_diagram(self.sort_m[mode], label=f'{sort_now.__name__[2:]}')
        else:
            for sort_now in _sort.sort_algo:
                self._load(sort_now.__name__)
                self._plot_diagram(self.sort_m[_sort.mode], label=f'{sort_now.__name__[2:]}')

    def _plot_diagram(self, mode_measur: dict[str: list[int | float]], label: str):
        plt.plot(self.sort_m["count"], mode_measur[self.param.value],
                 marker='o', linestyle='-', label=label)

    def _show_plot(self):
        plt.title(f'Залежність {name_mode[self.param.name]} від кількості елементів')
        plt.xlabel('Кількість елементів')
        plt.ylabel(ylabel_mode[self.param.name])

        plt.legend()

        plt.grid(True)
        mplcyberpunk.add_glow_effects()
        plt.show()

    def _load(self, sort_name: str):
        with open(f"measurement/{sort_name}.json", 'r') as file:
            self.sort_m = json.load(file)
