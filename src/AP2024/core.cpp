#include <iostream>
#include <random>

#include "core.h"

void SortsCore::swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

    swap_counter++;
}

void SortsCore::set(int *xp, int yp){
    *xp = yp;
    set_counter++;
}

void SortsCore::rand_array(int* array, size_t &size) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (size_t i = size - 1; i > 0; i--){
        std::uniform_int_distribution<> distribution(0, i+1);
        int j = (int)distribution(gen);

        std::swap(array[i], array[j]);
    }
}

void SortsCore::new_measurement(){
    set_counter=0;
    swap_counter=0;
    array_access=0;
    memory_req=0;
}

int SortsCore::get(int *arr, size_t index){
    array_access++;
    return arr[index];
}

int* SortsCore::create_array(size_t size){
    int* temp_arr = new int[size];
    memory_req += size * sizeof(temp_arr[0]);

    return temp_arr;
}

void SortsCore::cpp_mode_run(size_t size, std::string mode){
    new_measurement();
    int *array = create_array(size);

    for (size_t i=0;i<size;i++)
        array[i] = (int)(mode == "rev" ? size-i-1 : i);

    if(mode == "rand")
        rand_array(array, size);

    clock_t _start_sort = clock();
    cpp_run(array, size);

    clock_t _end_sort = clock();
    sort_t = (float(_end_sort - _start_sort)) / CLOCKS_PER_SEC;

    delete[] array;
}

void SortsCore::cpp_run(int *, size_t){}