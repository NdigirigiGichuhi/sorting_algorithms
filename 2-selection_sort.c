#include "sort.h"

/**
 * selection_sort - sorting array with selection sort
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_idx;
	int temp;

	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
		i++;
	}
}

