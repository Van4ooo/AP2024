#ifndef AP2024_SORTS_LIST_H
#define AP2024_SORTS_LIST_H

#include "../core.h"

namespace sorts{
    class BaseSort : public SortsCore{
    };

    class BubbleSort : public SortsCore{
    public:
        void cpp_run(int *, size_t) override;
    };

    class CombSort : public SortsCore{
    public:
        void cpp_run(int *, size_t) override;
    };

    class IntroSort : public SortsCore{
    public:
        void cpp_run(int *, size_t) override;
        void intro_sort_helper(int [], int *, int *, int);
        int* median_of_3(int *, int *, int *);
        int* partition(int[], int, int);
        void InsertionSort(int[], int *, int *);
        void HeapSort(int *, int *);
        void heapify(int *, int, int);
    };

    class SmoothSort : public SortsCore{
    private:
        int *data;
        size_t N;
        size_t tree_vector;
        unsigned short int first_tree;

        void heapify(size_t, size_t);
        void filter(size_t, size_t, bool test_children=true);
    public:
        void cpp_run(int *, size_t) override;
        void init_leonardo_heap(int *, size_t);
        void insertion_sort(size_t);
        void dequeue_max(size_t);
    };
}

#endif