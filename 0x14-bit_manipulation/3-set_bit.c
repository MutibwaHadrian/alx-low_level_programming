#include "main.h"

#define BITS_PER_LONG (sizeof(unsigned long int) * 8)


/**
 * set_bit -  a function that sets the value of a bit to 1 at a given index.
 * @n: a pointer to the unsigned long integer
 * @index: The index of the bit to set, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= BITS_PER_LONG)
	{
		return (-1);

	}

	*n |= (1ul << index);

	return (1);
}
