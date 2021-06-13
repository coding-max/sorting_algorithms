#include "sort.h"
#include"aux_functions.c"

/**
 * lomuto_partition - splits the array using the Lomuto's partition scheme
 * @array: the array to be splited
 * @left: the first index in the current partition of the array
 * @rigth: the last index in the current partition of the array
 * @size: number of elements in @array
 * Return: index for the new partition of the array
 */
size_t lomuto_partition(int *array, int left, int rigth, size_t size)
{
	int pivot = array[rigth];
	int i, pichu = left - 1;

	for (i = left; i < rigth; i++)
	{
		if (array[i] < pivot)
		{
			pichu++;
			swap(array, pichu, i);
			if (array[pichu] != array[i])
				print_array(array, size);
		}
	}
	swap(array, pichu + 1, rigth);
	if (array[++pichu] != array[rigth])
		print_array(array, size);
	return (pichu);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @left: the first index in the current partition of the array
 * @rigth: the last index in the current partition of the array
 * @size: number of elements in @array
 */
void quicksort(int *array, int left, int rigth, size_t size)
{
	int idx = 0;

	if (left < rigth)
	{
		idx = lomuto_partition(array, left, rigth, size);
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
