#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node at
 *				a given position.
 * @head: a pointer to the head of listint_t list
 * @idx: the index of the list where the new node should be added.
 *	Index starts at 0
 * @n: the value of the integer
 *
 * Returns: the address of the new node, or NULL if it failed
 *
 * if it is not possible to add the new node at index idx, do not add the
 *	new node and return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node, *fun = *head;
	unsigned int value;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		return (NULL);

	}
	node->n = n;

	if (idx == 0)
	{
		node->next = fun;
		*head = node;
		return (node);
	}

	for (value = 0; value < (idx - 1); value++)
	{
		if (fun == NULL || fun->next == NULL)
		{
			return (NULL);
		}
		fun = fun->next;
	}
	node->next = fun->next;
	fun->next = node;

	return (node);
}
