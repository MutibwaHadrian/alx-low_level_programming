#include <stdio.h>
#include "lists.h"

/**
 * print_listint - a funtion to print all elements in listint_t
 * @h: a head pointer
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	int place = 0;

	while (h)
	{

		printf("%d\n", h->n);
		h = h->next;
		place++;
	}
	return (place);
}
