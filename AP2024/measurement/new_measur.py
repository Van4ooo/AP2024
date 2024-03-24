import json
import progressbar

from AP2024.sorts import PySort
from AP2024.measurement.config import mode_sort, widgets


class Measurement:
    __sloth__ = ('sort_algo', 'c_x', 'max_c', 'mes_sort')

    def __init__(self, sort: PySort, c_x: float = 1.5, max_c: int = 50_000_000):
        self.sort_algo = sort()
        self.c_x = c_x
        self.max_c = max_c
        self.mes_sort = {'count': self._add_count()}

        for mode in mode_sort:
            self.mes_sort[mode] = self._measur_by_mode(mode)

        self.write_to_json()

    def _measur_by_mode(self, mode: str) -> dict[str:list[int | float]]:
        sort_m = {"time": [], "memory": [], "access": [], "swap/set": []}

        bar = progressbar.ProgressBar(maxval=self.max_c, widgets=widgets).start()

        for _c in self.mes_sort['count']:
            self.sort_algo.run(_c, mode)

            sort_m["time"].append(round(self.sort_algo.sort_time, 4))
            sort_m["memory"].append(self.sort_algo.mem_req)
            sort_m["access"].append(self.sort_algo.access_c)
            sort_m["swap/set"].append(self.sort_algo.swap_c + self.sort_algo.set_c)

            bar.update(_c)

        return sort_m

    def _add_count(self) -> list[int]:
        _count = [now := 1024]

        while now < self.max_c:
            _count.append(now)
            now = int(self.c_x * now)

        _count.append(self.max_c)

        return _count

    def write_to_json(self) -> None:
        with open(f"measurement/{self.sort_algo.__class__.__name__}.json", 'w') as json_file:
            json.dump(self.mes_sort, json_file, indent=4)


__all__ = ("Measurement",)
