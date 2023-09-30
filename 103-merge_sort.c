#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size) {
    int i = 0, j = 0, k = 0;
    int *temp;

    temp = (int *)malloc((left_size + right_size) * sizeof(int));

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            temp[k++] = left[i++];
        } else {
            temp[k++] = right[j++];
        }
    }

    while (i < left_size) {
        temp[k++] = left[i++];
    }

    while (j < right_size) {
        temp[k++] = right[j++];
    }

    for (i = 0; i < left_size + right_size; i++) {
        array[i] = temp[i];
    }

    free(temp);
}

void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        int  mid, *left, *right;
	size_t i, left_size, right_size;

	mid  = size / 2;
	left = array;
	right = array + mid;
	left_size = mid;
	right_size = size - mid;

        printf("Merging...\n[left]: ");
        for (i = 0; i < left_size; i++)
	{
            printf("%d", left[i]);
            if (i < left_size - 1)
	    {
                printf(", ");
            }
        }
        printf("\n[right]: ");
        for (i = 0; i < right_size; i++)
	{
            printf("%d", right[i]);
            if (i < right_size - 1)
	    {
                printf(", ");
            }
        }
        printf("\n");

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        merge(array, left, left_size, right, right_size);

        printf("[Done]: ");
        for (i = 0; i < size; i++)
	{
            printf("%d", array[i]);
            if (i < size - 1)
	    {
                printf(", ");
            }
        }
        printf("\n");
    }
}
