#include "sort.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int* array, int low, int high, size_t n) {
    int i, j, pivot;

    pivot = array[high];
    i = low;
    j = high;

    while (i < j) {
        while (array[i] <= pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i < j) {
            swap(&array[i], &array[j]);
	    print_array(array, n);
        }
    }
    array[low] = array[j];
    array[j] = pivot;


    return j;
}

void recursion_sort(int* array, int low, int high, size_t n) {
    int j;

    if (low < high) {
        j = partition(array, low, high, n);
        recursion_sort(array, low, j - 1, n);
        recursion_sort(array, j + 1, high, n);
    }
}

void quick_sort(int* array, size_t size) {
    int low = 0;
    int high = size - 1;
    recursion_sort(array, low, high, size);
}

