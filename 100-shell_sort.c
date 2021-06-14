#include "sort.h"

/**
 * selection_shell_sort - sorts the sub-array of integers in ascending order
 * using the Selection algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 * @gap: interval that subdivide the array
 * @index: initial position to sort
 */
void selection_shell_sort(int *array, size_t size, size_t gap, size_t index)
{
	size_t i, idx, min_idx;
	int tmp, swapped = 0;

	for (i = index; i < size; i = i + gap)
	{
		swapped = 0;
		min_idx = i;
		for (idx = i + gap; idx < size; idx = idx + gap)
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
		}
	}
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm and the Knuth sequence
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap = 1;

	if (!array || size < 2)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = 0; i < size; i++)
			selection_shell_sort(array, size, gap, i);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
