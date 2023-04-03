#include <stdio.h>
#include "lists.h"

/**
 * listint_len - A function that returns the number of elements
 *		in a linked listint_t list.
 * @h: a pointer to the head of the linked list
 *
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	int place = 0;

	while (h)
	{
		h = h->next;
		place++;
	}
	return (place);
}
