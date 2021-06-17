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

/**
 * swap_node - swap to nodes in the doubly linked list
 * @list: pointer to the doubly linked list
 * @node: node to be swapped with the next one
 */
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}
