#include <iostream>
#include <cmath>
#include "sorts_list.h"


void sorts::IntroSort::cpp_run(int *array, size_t size){
    int d = 2 * log(size);

    intro_sort_helper(array, array, array+size-1, d);
}

void sorts::IntroSort::intro_sort_helper(int array[], int *begin, int *end, int depth){
    size_t size = end - begin;

    if(size < 16){
        sorts::IntroSort::InsertionSort(array, begin, end);
        return;
    }

    if (depth == 0){
        sorts::IntroSort::HeapSort(begin, end);
        return;
    }

    int* pivot = median_of_3(begin, begin+size/2, end);
    swap(pivot, end);

    int* partition_p = partition(array, begin-array, end-array);
    intro_sort_helper(array, begin, partition_p-1, depth-1);
    intro_sort_helper(array, partition_p+1, end, depth-1);
}

int* sorts::IntroSort::median_of_3(int *first, int *second, int *third){
    int a = *first, b = *second, c = *third;
    array_access+=3;

    if (a < b && b < c) return second;
    if (a < c && c <= b) return third;
    if (b <= a && a < c) return first;
    if (b < c && c <= a) return third;
    if (c <= a && a < b) return first;
    if (c <= b && b <= a) return second;
}

int* sorts::IntroSort::partition(int array[], int low, int high){
    int pivot = get(array, high);
    int i = low - 1;

    for(int j=low;j<high-1;j++){
        if(get(array, j) <= pivot){
            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);
    return array+i+1;
}


void sorts::IntroSort::InsertionSort(int array[], int *begin, int *end){
    int left = begin - array;
    int right = end - array;

    for(int i=left+1;i<=right;i++){
        int key = get(array, i);
        int j = i-1;

        while(j >= left && get(array, j) > key){
            set(&array[j+1], array[j]);
            j = j-1;
        }
        set(&array[j+1], key);
    }
}


void sorts::IntroSort::HeapSort(int *begin, int *end){
     int n = end - begin;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(begin, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&begin[0], &begin[i]);
        heapify(begin, i, 0);
    }
}

void sorts::IntroSort::heapify(int* array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && get(array, left) > get(array, largest)) largest = left;
    if (right < n && get(array, right) > get(array, largest)) largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}