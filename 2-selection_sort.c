#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, idx, min_idx;
	int tmp, swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		min_idx = i;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[idx] < array[min_idx])
			{
				min_idx = idx;
				swapped = 1;
			}
		}
		if (swapped)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
