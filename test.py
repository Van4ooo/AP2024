from AP2024.sorts import PyCombSort, PyIntroSort, PySmoothSort
from AP2024.measurement import Measurement
from AP2024.diagram import Diagram, D, SortParam


if __name__ == '__main__':
    Diagram(
        SortParam.time,
        D([PyIntroSort], 'all'),
        D([PyIntroSort, PySmoothSort, PyCombSort], 'sort'),
        D([PyIntroSort, PySmoothSort, PyCombSort], 'rev'),
        D([PyIntroSort, PySmoothSort, PyCombSort], 'rand'),
        one_diagram=False
    )
