#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: a doubly linked list to sort
 * Return: void
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *tem = *(list);

	while (list && tem)
	{
		aux = tem->next;
		while (tem->prev && tem->prev->n > tem->n)
		{
			if (tem->next)
			{
				tem->next->prev = tem->prev;
				tem->prev->next = tem->next;
				if (!tem->prev->prev)
				{
					tem->prev->prev = tem;
					tem->next = tem->prev;
					tem->prev = NULL;
					*list = tem;
				} else
				{
					tem->next = tem->prev;
					tem->prev = tem->prev->prev;
					tem->prev->next = tem;
					tem->next->prev = tem;
				}
			} else
			{
				tem->next = tem->prev;
				tem->prev = tem->prev->prev;
				tem->next->next = NULL;
				tem->next->prev = tem;
				if (tem->prev)
					tem->prev->next = tem;
				else
					*list = tem;
			}
			print_list(*list);
		}
		tem = aux;
	}
}
