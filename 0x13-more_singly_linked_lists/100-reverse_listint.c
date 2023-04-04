#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t linked list.
 * @head: a pointer to the head of the listint_t list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *first, *second;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}

	second = NULL;

	while ((*head)->next != NULL)
	{
		first = (*head)->next;
		(*head)->next = second;
		second = *head;
		*head = first;
	}

	(*head)->next = second;

	return (*head);

}
