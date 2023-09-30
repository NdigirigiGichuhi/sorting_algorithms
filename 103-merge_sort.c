#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into the original
 * @array: original array
 * @left: left sub-array
 * @left_size: Size of the left sub-array
 * @right: right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, left_size, right_size;
	int *left, *right

	mid = size / 2;
	left = array;
	right = array + mid;
	left_size = mid;
	right_size = size - mid;

	if (size <= 1)
                return;

	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, left_size, right, right_size);
}
