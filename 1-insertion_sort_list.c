#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: The list to sort
 * Return: Nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *tmp;

	if (!list || !(*list))
		return;

	ptr = ptr->next;
	while (ptr)
	{
		while (ptr->prev && ptr->n < ptr->prev->n)
		{
			tmp = ptr->prev;
			tmp->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = tmp;
			ptr->next = tmp;
			ptr->prev = tmp->prev;
			tmp->prev = ptr;

			if (!ptr->prev)
				*list = ptr;
			else
				ptr->prev->next = ptr;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}
