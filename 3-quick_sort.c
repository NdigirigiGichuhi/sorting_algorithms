#include "sort.h"

/**
 * swap_int - swaps two ints
 * @a: first int to be swapped
 * @b: second int to be wapped
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partions an array
 * @array: array to partition
 * @low: index of lower bound
 * @high: index of upper bound
 * @n: size of array be sorted
 * Return: index of pivot after swapped
 */
int partition(int *array, int low, int high, size_t n)
{

	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++; /*index of smaller element incremented*/
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, n);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		swap_int(&array[i + 1], &array[j]); /*swap pivot with i + 1 element*/
		print_array(array, n);
	}
	return (i + 1); /*current position of pivot*/
}
/*
 * recursion_sort - recursion for partioning the two divides
 * @array: array to be partition
 * @low: index for lower bound
 * @high: index for upper bound
 * @n: size of array
 */

void recursion_sort(int *array, int low, int high, size_t n)
{
	int j;

	if (low < high)
	{
		j = partition(array, low, high, n);
		recursion_sort(array, low, j - 1, n);
		recursion_sort(array, j + 1, high, n);
	}
}
/**
 * quick_sort - function that sorts array
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	recursion_sort(array, low, high, size);
}
