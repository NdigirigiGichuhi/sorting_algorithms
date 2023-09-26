#include "sort.h"

/**
 * merge - merges two arrays
 * @array: array to merge
 * @low: index zero
 * @mid: middle index
 * @high: largest index
 */

void merge(int *array, int low, int mid, int high)
{
	int array1[100], array2[100], result[100];
	int i = 0, j = 0, k = 0;

	printf("[left]: %d", low);

	for (i = 0; i < mid - low + 1; i++)
		array1[i] = array[low + i];
	for (i = 0; i < high - mid; i++)
		array2[i] = array[mid + 1 + i];
	i = 0;
	while (i < mid - low + 1 && j < high - mid)
	{
		if (array1[i] < array2[j])
		{
			result[k] = array1[i], k++, i++;
		}
		else
		{
			result[k] = array2[j], k++, j++;
		}
	}

	while (i < mid - low + 1)
	{
		result[k] = array1[i];
		k++;
		i++;
	}

	while (j < high - mid)
	{
		result[k] = array2[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		array[i] = result[i - low];
	}
}

/**
 * recursion - divides array
 * @array: array to divide
 * @low: index zero
 * @high: largest index
 */

void recursion(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		recursion(array, low, mid);
		recursion(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

/**
 * merge_sort - sorts array
 * @array: array to sort
 * @size: size of array.
 */

void merge_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;

	recursion(array, low, high);

}
