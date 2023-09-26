#include "sort.h"

/**
 * insertion_sort_list - sorting doubly linked list
 * @list: pointer to pointer of linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *one, *current, *sorted, *temp;

	if (!list || (*list)->next == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		sorted = current->prev;
		while (sorted && sorted->n > current->n)
		{
			temp = current->next;
			sorted = current->prev;
			one = current->prev->prev;

			if (temp != NULL)
				temp->prev = sorted;
			sorted->next = temp;
			sorted->prev = current;
			current->next = sorted;
			current->prev = one;

			if (one != NULL)
				one->next = current;
			if (one == NULL)
				*list = current;
			sorted = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
