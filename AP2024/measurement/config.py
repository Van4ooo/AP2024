import progressbar

mode_sort = ["rev", "rand", "sort"]
widgets = [
            f'Sorting... ', progressbar.Percentage(),
            ' ', progressbar.Bar(marker='█', left='[', right=']'),
]

__all__ = ("mode_sort", "widgets")
