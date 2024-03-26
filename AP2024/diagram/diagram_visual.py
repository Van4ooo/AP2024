import matplotlib.pyplot as plt
import json

from AP2024.diagram.diagram_object import SortParam, D
from AP2024.measurement import mode_sort


class Diagram:
    sort_m: dict

    def __init__(self, param: SortParam, *args, one_diagram=True):
        self.param = param

        for sort_m in args:
            if not isinstance(sort_m, D):
                continue
            self.plot_sort(_sort=sort_m)

            if not one_diagram:
                self._show_plot()

        if one_diagram:
            self._show_plot()

    def plot_sort(self, _sort: D):
        if _sort.mode == "all":
            for sort_now in _sort.sort_algo:
                self._load(sort_now.__name__)
                for mode in mode_sort:
                    self._plot_diagram(self.sort_m[mode], label=f'{sort_now.__name__[2:]}:{mode}')
        else:
            for sort_now in _sort.sort_algo:
                self._load(sort_now.__name__)
                self._plot_diagram(self.sort_m[_sort.mode], label=f'{sort_now.__name__[2:]}:{_sort.mode}')

    def _plot_diagram(self, mode_measur: dict[str: list[int | float]], label: str):
        plt.plot(self.sort_m["count"], mode_measur[self.param.value],
                 marker='o', linestyle='-', label=label)

    def _show_plot(self):
        plt.title(f'Залежність {self.param.name} від кількості елементів')
        plt.xlabel('Кількість елементів')
        plt.ylabel(f'{self.param.name}')

        plt.legend()

        plt.grid(True)
        plt.show()

    def _load(self, sort_name: str):
        with open(f"measurement/{sort_name}.json", 'r') as file:
            self.sort_m = json.load(file)
