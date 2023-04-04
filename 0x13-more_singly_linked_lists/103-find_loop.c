#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list.
 *
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The address of the node where the loop starts, or
 *		NULL if there is no loop
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pan, *food;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}

	pan = head->next;
	food = (head->next)->next;

	while (food)
	{
		if (pan == food)
		{
			pan = head;

			while (pan != food)
			{
				pan = pan->next;
				food = food->next;
			}

			return (pan);
		}

		pan = pan->next;
		food = (food->next)->next;
	}

	return (NULL);
}
