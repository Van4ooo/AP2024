# cython: c_string_type=unicode, c_string_encoding=utf8
# distutils: language = c++
from AP2024 cimport BubbleSort, CombSort, BaseSort, IntroSort


cdef class PySort:
    cdef BaseSort* ap_sort

    def __dealloc__(self):
        del self.ap_sort

    def __repr__(self):
        return f"{self.__class__.__name__}(set={self.set_c}, swap={self.swap_c}, get={self.access_c}, time={self.sort_time})\n"

    @property
    def swap_c(self):
        return self.ap_sort.swap_counter

    @property
    def set_c(self):
        return self.ap_sort.set_counter

    @property
    def access_c(self):
        return self.ap_sort.array_access

    @property
    def mem_req(self):
        return self.ap_sort.memory_req

    @property
    def sort_time(self):
        return self.ap_sort.sort_t

    def run(self, size_t size, string mode):
        self.ap_sort.cpp_mode_run(size, mode)


cdef class PyBubbleSort(PySort):
    def __cinit__(self):
        self.ap_sort = <BaseSort*>(new BubbleSort())


cdef class PyCombSort(PySort):
    def __cinit__(self):
        self.ap_sort = <BaseSort*>(new CombSort())


cdef class PyIntroSort(PySort):
    def __cinit__(self):
        self.ap_sort = <BaseSort*>(new IntroSort())