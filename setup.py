from setuptools import setup, Extension
from Cython.Build import cythonize

setup(
    name="AP2024",
    author="Ivan Rybachyk",

    ext_modules=cythonize(Extension(
        name="AP2024.sorts",
        sources=["AP2024/core-sorts/core_sorts.pyx", "AP2024/core-sorts/core.cpp",
                 "AP2024/core-sorts/sorts_algo/bubble_sort.cpp",
                 "AP2024/core-sorts/sorts_algo/comb_sort.cpp",
                 "AP2024/core-sorts/sorts_algo/intro_sort.cpp",
                 "AP2024/core-sorts/sorts_algo/smooth_sort.cpp"
                 ],

        language="c++",
    )))
