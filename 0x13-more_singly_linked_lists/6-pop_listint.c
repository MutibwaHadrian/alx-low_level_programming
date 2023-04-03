#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - a function that deletes the head node of a listint_t linked
 *		list, and returns the head node’s data (n).
 * @head: a pointer to the head of the listint_t list
 *
 * Return: if the linked list is empty return 0
 */

int pop_listint(listint_t **head)
{
	listint_t *place;
	int value;

	if (*head == NULL)
		return (0);

	place = *head;
	value = (*head)->n;
	*head = (*head)->next;

	free(place);

	return (value);
}
