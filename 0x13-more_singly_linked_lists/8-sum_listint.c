#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - a function that returns the sum of all the data (n) of
 *		a listint_t linked list.
 * @head: a pointer to the head of the listint_t list
 *
 * Return: if the list is empty, return 0
 */

int sum_listint(listint_t *head)
{
	int total = 0;

	while (head)
	{
		total += head->n;
		head = head->next;

	}
	return (total);

}
