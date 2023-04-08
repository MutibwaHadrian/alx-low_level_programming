#include "main.h"

/**
 * fli_bits - a function that returns the number of bits you would need to
 *             flip to get from one number to another.
 * @n: First unsigned long int
 * @m: Second unsigned long int
 *
 * Return: Number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int num = n ^ m;
	unsigned int flip = 0;

	while (num)
	{
		flip += num & 1;
		num >>= 1;
	}

	return (flip);
}
