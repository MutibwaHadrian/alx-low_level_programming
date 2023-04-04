#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

size_t loop_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * loop_listint_count - the  function that counts the number of unique nodes
 *			in a list.
 * @head: a pointer to the head of the listint_t.
 *
 * Return: If the list is not looped - (0)
 */
size_t loop_listint_count(listint_t *head)
{

	listint_t *pan, *food;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
	{
		return (0);
	}

	pan = head->next;
	food = (head->next)->next;

	while (food)
	{
		if (pan == food)
		{
			pan = food;

			while (pan != food)
			{
				nodes++;
				pan = pan->next;
				food = food->next;
			}

			pan = pan->next;

			while (pan != food)
			{
				nodes++;
				pan = pan->next;
			}
			return (nodes);
		}
		pan = pan->next;
		food = (food->next)->next;
	}
	return (0);
}

/**
 * free_listint_safe - a function that frees a listint_t list.
 * @h: a pointer to the head of the listint_t list
 *
 * Return: The size of the list that was free’d.
 *
 * Description: The function sets the head to NULL
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *value;
	size_t nodes, place;

	nodes = loop_listint_count(*h);

	if (nodes == 0)
	{

		for (; h != NULL && *h != NULL; nodes++)
		{
			value = (*h)->next;
			free(*h);
			*h = value;
		}

	}

	else
	{

		for (place = 0; place < nodes; place++)
		{
			value = (*h)->next;
			free(*h);
			*h = value;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodes);
}
