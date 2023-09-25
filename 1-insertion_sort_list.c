#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;
        current = current->next;
        while (temp && temp->prev && temp->prev->n > temp->n)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;
            if (!temp->prev)
                *list = temp;
            else
                temp->prev->next = temp;
            print_list(*list);
        }
    }
}
