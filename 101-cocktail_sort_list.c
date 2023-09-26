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
 * forward_loop - Sorts the list forwards
 * @list: Double pointer to the head of the list
 * @current: Double pointer to the current node being evaluated
 * @swapped: Pointer to the swapped variable from cocktail_sort_list function
 */
void forward_loop(listint_t **list, listint_t **current, int *swapped)
{
	while (*current && (*current)->next)
	{
		if ((*current)->n > (*current)->next->n)
		{
			swap_nodes(list, *current, (*current)->next);
			*swapped = 1;
			print_list(*list);
			*current = (*current)->prev;
		}
		else
		{
			*current = (*current)->next;
		}
	}
}

/**
 * backward_loop - Sorts the list backwards
 * @list: Double pointer to the head of the list
 * @current: Double pointer to the current node being evaluated
 * @swapped: Pointer to the swapped variable from cocktail_sort_list function
 */
void backward_loop(listint_t **list, listint_t **current, int *swapped)
{
	*swapped = 0;
	while (*current && (*current)->prev)
	{
		if ((*current)->n < (*current)->prev->n)
		{
			swap_nodes(list, (*current)->prev, *current);
			*swapped = 1;
			print_list(*list);
		}
		else
		{
			*current = (*current)->prev;
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (!list || !*list)
		return;

	current = *list;
	while (swapped)
	{
		forward_loop(list, &current, &swapped);
		if (swapped)
			backward_loop(list, &current, &swapped);
	}
}
