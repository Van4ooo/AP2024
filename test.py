from AP2024.sorts import PyCombSort, PyIntroSort, PySmoothSort
from AP2024 import Measurement, Diagram, D, SortParam


if __name__ == '__main__':
    Diagram(
        SortParam.time,
        D([PyIntroSort, PySmoothSort, PyCombSort], 'sort'),
        D([PyIntroSort, PySmoothSort, PyCombSort], 'rev'),
        D([PyIntroSort, PySmoothSort, PyCombSort], 'rand'),
        one_diagram=False
    )
