#include "sorts_list.h"

void sorts::BubbleSort::cpp_run(int* array, size_t size) {
    size_t i, j;
    bool swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = false;

        for (j = 0; j < size - i - 1; j++) {
            if (get(array, j) > get(array, j + 1)) {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}