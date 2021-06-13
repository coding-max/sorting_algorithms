#include"sort.h"

/**
 * swap - swap to integers in the array
 * @array: the array to be sorted
 * @a: item to swap
 * @b: item to swap
 */
void swap(int *array, size_t a, size_t b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}
