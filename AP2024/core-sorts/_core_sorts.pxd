from libcpp.string cimport string


cdef extern from "sorts_algo/sorts_list.h" namespace "sorts":
    cdef cppclass BaseSort:
        size_t swap_counter;
        size_t set_counter;
        size_t array_access;
        size_t memory_req;
        float sort_t;
        void cpp_mode_run(size_t, string);

    cdef cppclass CombSort(BaseSort):
        CombSort() except +;

    cdef cppclass IntroSort(BaseSort):
        IntroSort() except +;

    cdef cppclass SmoothSort(BaseSort):
        SmoothSort() except +;