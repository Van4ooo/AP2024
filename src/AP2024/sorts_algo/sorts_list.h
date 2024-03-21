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
}

#endif