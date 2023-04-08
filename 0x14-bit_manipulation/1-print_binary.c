#include <stdio.h>
#include "main.h"

/**
 * print_binary - a function that prints the binary representation of a number
 * @n: unsigned long int for the number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int i;
	unsigned long int index = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int print = 0;


	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 0; i < sizeof(unsigned long int) * 8; i++)
	{
		if ((n & index) || print)
		{
			if (n & index)
			{
				_putchar('1');
			}
			else
			{
				_putchar('0');
			}

			print = 1;
		}

		index >>= 1;
	}


}
