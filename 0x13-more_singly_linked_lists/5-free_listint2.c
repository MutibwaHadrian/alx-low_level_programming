#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list.
 * @head: a pointer to the head of the listint_t list.
 *
 * The function sets the head to NULL
 */

void free_listint2(listint_t **head)
{
	listint_t *value;

	if (head == NULL)
		return;

	while (*head)
	{
		value = (*head)->next;
		free(*head);
		*head = value;
	}
	head = NULL;

}

