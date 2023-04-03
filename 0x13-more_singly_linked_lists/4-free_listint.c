#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * free_listint - a function that frees a listint_t list.
 * @head: a point of the head of the listint_t
 */

void free_listint(listint_t *head)
{
	listint_t *value;

	while (head)
	{
		value = head->next;
		free(head);
		head = value;
	}
}
