#include "main.h"

#define BITS_PER_LONG (sizeof(unsigned long int) * 8)

/**
 * clear_bit - a function that sets the value of a bit to 0 at a given index.
 * @n: a pointer to the unsigned long integer
 * @index: index of the bit to be cleared, strating from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= BITS_PER_LONG)
	{
		return (-1);
	}

	*n &= ~(1UL << index);

	return (1);
}
