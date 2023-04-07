#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b: a pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in
 *         the string b that is not 0 or 1f b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	unsigned int index;

	if (b == NULL)
	{
		return (0);
	}

	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
		{
			return (0);
		}

		index = *b - '0';
		num = (num << 1) | index;
	}

	return (num);
}
