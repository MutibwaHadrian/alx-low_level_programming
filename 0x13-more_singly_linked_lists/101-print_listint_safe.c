#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - a function that prints a listint_t linked list.
 * @head: a pointer to the head of the listint_t list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num = 0;
	listint_t *index = (void *)head, *value = 0;
	int node = 0;

	while (index != NULL)
	{
		if (node == 0)
		{
			value = index;
			printf("[%p] %d\n", (void *)index, index->n);
		}
		if (node == 1)
		{
			if (value <= index)
			{
				printf("-> [%p] %d\n", (void *)index, index->n);
				return (num);
			}
			printf("[%p] %d\n", (void *)index, index->n);
		}
		num += 1;
		value = index;
		index = index->next;
		node = 1;

	}
	return (num);
}
