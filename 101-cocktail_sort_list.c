#include "sort.h"
#include "aux_functions.c"

/**
 * cocktail_sort_list - sorts a list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *aux;

	if (!list)
		return;

	aux = *list;
	while (swapped)
	{
		for (swapped = 0; aux->next;)
		{
			if (aux->next->n < aux->n)
			{
				swap_node(list, aux);
				print_list(*list);
				swapped++;
			}
			else
				aux = aux->next;
		}
		if (!swapped)
			break;
		for (swapped = 0; aux->prev;)
		{
			if (aux->prev->n > aux->n)
			{
				swap_node(list, aux->prev);
				print_list(*list);
				swapped++;
			}
			else
				aux = aux->prev;
		}
	}
}
