import dataclasses
from enum import Enum

from ..sorts import PySort


@dataclasses.dataclass
class D:
    sort_algo: list[PySort]
    mode: str


class SortParam(Enum):
    time: str = "time"
    memory: str = "memory"
    access: str = "access"
    swap_set: str = "swap/set"
