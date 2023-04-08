#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index.
 * @n: unsigned long interger
 * @index: the index, starting from 0 of the bit you want to get
 *
 * Returns: the value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	n >>= index;

	return (n & 1);
}
