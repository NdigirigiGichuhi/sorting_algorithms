#include "sort.h"
/**
 * find_max - finds max element in array
 * @array: array to loop
 * @n: no. of elements
 * Return: returns maximum integer
 */

int find_max(int *array, size_t n)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
/**
 * counting_sort - counts occurences of elements in array
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int i;
	int *count_array;
	int max, idx = 0;
	size_t x;

	max = find_max(array, size);
	count_array = (int *)malloc(sizeof(int) * (max + 1));
	for (i = 0; i < max + 1; i++)	/*initializes counting array with 0's*/
		count_array[i] = 0;
	for (x = 0; x < size; x++)	/*counts occurences of each element*/
		count_array[array[x]]++;

	for (i = 0; i <= max; i++)	/*using counting array to created sorted array*/
	{
		while (count_array[i] > 0)
		{
			array[idx] = i;
			idx++;
			count_array[i]--;
		}
	}
	free(count_array);
}
