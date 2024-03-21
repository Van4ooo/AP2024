from setuptools import setup, Extension
from Cython.Build import cythonize

setup(
    ext_modules=cythonize(Extension(
        name="ap2024",
        sources=["src/ap2024.pyx", "src/AP2024/core.cpp",
                 "src/AP2024/sorts_algo/bubble_sort.cpp",
                 "src/AP2024/sorts_algo/comb_sort.cpp",
                 "src/AP2024/sorts_algo/intro_sort.cpp"
                 ],

        language="c++",
    )))
