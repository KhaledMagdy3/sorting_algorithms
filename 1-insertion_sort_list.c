#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: listint_t ** (pointer to pointer to the head of the list)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = prev;

			temp->prev = prev->prev;
			prev->next = temp->next;
			temp->next = prev;
			prev->prev = temp;

			print_list(*list);

			prev = temp->prev;
		}

		current = current->next;
	}
}
