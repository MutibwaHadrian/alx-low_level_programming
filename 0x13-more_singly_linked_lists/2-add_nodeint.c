#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint - a function to add a new node at the beginning of a listint_t
 *
 * @head: a pointer to the head of listint_t
 *
 * @n: value of the integer of the node in listint_t
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node = 0;

	node = malloc(sizeof(listint_t));

	if (node == NULL)
	{
		return (NULL);
	}

	node->n = n;

	node->next = *head;

	*head = node;

	return (node);
}
