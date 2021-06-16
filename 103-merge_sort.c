#include "sort.h"

/**
 * merge_topdown - sorts the array of integers in ascending order
 * using TopDown merge sort algorithm
 * @arr_o: the array to be sorted
 * @arr_c: number of elements in @array
 * @idx_l: number of elements in @array
 * @idx_m: idk
 * @idx_r: number of elements in @array
 */
void merge_topdown(int *arr_o, int *arr_c,
					int idx_l, int idx_m, int idx_r)
{
	int i, j, k;

	i = idx_l, j = idx_m, k = idx_l;

	for (k = idx_l; k < idx_r; k++)
	{
		if (i < idx_m && (j >= idx_r || arr_o[i] <= arr_o[j]))
		{
			arr_c[k] = arr_o[i];
			i++;
		}
		else
		{
			arr_c[k] = arr_o[j];
			j++;
		}
	}

}


/**
 * merge_recursive - sorts the array of integers in ascending order
 * using TopDown merge sort algorithm
 * @arr_o: the array to be sorted
 * @arr_c: number of elements in @array
 * @idx_l: number of elements in @array
 * @idx_r: number of elements in @array
 */
void merge_recursive(int *arr_o, int *arr_c,
						int idx_l, int idx_r)
{
	int idx_m;

	if (idx_r - idx_l <= 1)
		return;

	idx_m = (idx_r + idx_l) / 2;

	merge_recursive(arr_c, arr_o, idx_l, idx_m);
	merge_recursive(arr_c, arr_o, idx_m, idx_r);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr_c + idx_l, idx_m - idx_l);
	printf("[right]: ");
	print_array(arr_c + idx_m, idx_r - idx_m);
	printf("[Done]: ");
	merge_topdown(arr_c, arr_o, idx_l, idx_m, idx_r);
	print_array(arr_o + idx_l, idx_r - idx_l);
}


/**
 * merge_sort - sorts the array of integers in ascending order
 * using TopDown merge sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * (size + 1));
	if (!copy)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	merge_recursive(array, copy, 0, size);
	free(copy);
}
