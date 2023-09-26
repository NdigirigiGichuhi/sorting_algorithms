#include "sort.h"

void insertion_sort_list(listint_t **list) {
	listint_t *current, *holder, *temp, *previous, *head;
	int size = 0;

	if (*list == NULL || (*list)->next == NULL) {
		return; /* Nothing to sort*/
	}

	/* Calculate the size of the list*/
	temp = *list;
	while (temp != NULL) {
		size++;
		temp = temp->next;
	}

	for (current = (*list)->next; current != NULL; current = current->next) {
		holder = current;
		previous = current->prev;

		while (previous != NULL && holder->n < previous->n) {
			/* Adjust pointers to perform the insertion*/
			head = previous->prev;
			if (head != NULL) {
				head->next = holder;
			}
			previous->prev = holder;
			holder->prev = head;

			if (previous->next != NULL) {
				previous->next->prev = current;
			}
			current->next = previous->next;
			previous->next = current;
			current->prev = previous;

			/* Update the list pointer if needed*/
			if (previous == *list) {
				*list = current;
			}
		}
	}
}

