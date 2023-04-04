#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node at index
 *				index of a listint_t linked list.
 * @head: a pointer to the head of the listint_t list
 * @index: the index of the node that should be deleted. Index starts at 0
 *
 * Return: On succeeded - 1.
 *	On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *fun = *head;
	unsigned int value;

	if (fun == NULL)
	{
		return (-1);

	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(fun);
		return (1);

	}

	for (value = 0; value < (index - 1); value++)
	{
		if (fun->next == NULL)
		{
			return (-1);

		}
		fun = fun->next;
	}

	node = fun->next;
	fun->next = node->next;
	free(node);
	return (1);
}
