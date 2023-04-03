#include <stdio.h>
#include "lists.h"

/**
 * print_listint - a funtion to print all elements in a list
 * @h: number of elements
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	int place = 0;

	while (h)
	{

		printf("%i\n", h->n);
		h = h->next;
		place++;
	}
	return (place);
}
