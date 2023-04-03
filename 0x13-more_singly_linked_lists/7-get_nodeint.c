#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth node
 *			of a listint_t linked list.
 * @head: a pointer to the head of the listint_t list
 * @index: the index of the node, starting at 0
 *
 * Return: if the node does not exist, return NULL, else return the node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int value;

	for (value = 0; value < index; value++)
	{
		if (head == NULL)
		{
			return (NULL);
		}
		head = head->next;

	}
	return (head);

}
