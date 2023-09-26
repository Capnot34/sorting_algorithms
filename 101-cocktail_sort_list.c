#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Pointer to the left node to be swapped
 * @right: Pointer to the right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *prev, *next;

	prev = left->prev;
	next = right->next;

	if (prev)
		prev->next = right;
	else
		*list = right;

	if (next)
		next->prev = left;

	right->prev = prev;
	left->next = next;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *last_swapped;

	if (!list || !*list)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current && current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				last_swapped = current->prev;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		current = last_swapped;
		swapped = 0;
		while (current && current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	}
}
