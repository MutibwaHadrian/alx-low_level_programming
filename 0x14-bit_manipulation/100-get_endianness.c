#include "main.h"

/**
 * get_endianness - a function that checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int index = 1;
	char *ptr = (char *)&index;

	if (*ptr)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
