#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, swapped = 0;
	size_t i, n = size;

	while (swapped == 0)
	{
		swapped = 1;
		for (i = 1; i < n; i++)
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				swapped = 0;
				print_array(array, size);
			}
	}
}
