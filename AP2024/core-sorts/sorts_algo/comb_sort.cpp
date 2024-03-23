#include "sorts_list.h"

void sorts::CombSort::cpp_run(int *array, size_t size){
    size_t gap = size;
    bool swapped = true;

    while (gap != 1 || swapped == true){
        gap = (gap*10)/13;
        gap = (gap < 1 ? 1 : gap);

        swapped = false;

        for (size_t i=0; i<size-gap; i++){
            if (get(array, i) > get(array, i+gap)){
                swap(&array[i], &array[i+gap]);
                swapped = true;
            }
        }
    }
}