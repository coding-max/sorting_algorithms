#include "sort.h"

/**
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @left: to-do
 * @rigth: to-do
 * @size: to-do
 */
size_t partition(int *array, size_t left, size_t rigth, size_t size)
{
	int pivot = array[rigth];
	int tmp;
	size_t pichu = left - 1, i;

	if (left == 0)
		pichu = 0;
	for (i = left; i < rigth; i++)
	{
		if (array[i] < pivot)
		{
			pichu++;
			tmp = array[pichu];
			array[pichu] = array[i];
			array[i] = tmp;
		}
	}
	tmp = array[pichu + 1];
	array[pichu + 1] = array[rigth];
	array[rigth] = tmp;
	print_array(array, size);
	return (pichu + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @left: to-do
 * @rigth: to-do
 * @size: to-do
 */
void quicksort(int *array, size_t left, size_t rigth, size_t size)
{
	size_t idx = 0;

	if (left < rigth)
	{
		idx = partition(array, left, rigth, size);
		quicksort(array, left, idx - 1, size);
		quicksort(array, idx + 1, rigth, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
