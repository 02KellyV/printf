#include "holberton.h"

/**
 * print_ptr - print_base16_upper_lower
 * @arg: va_list parameter
 * @base: base 10, 8 16, etc...
 * Description: This function print address pointer
 * in representation parameter for print hexadecimal format
 * Return: address pointer
 */

int print_ptr(va_list arg)
{
	unsigned long int dec, buffr;
	char c[100];
	int count, n, i;

	dec = (unsigned long int)va_arg(arg, void*);
	buffr = dec;
	count = 1;
	i = 0;

	while (buffr)
	{
		buffr /= 16;
		count ++;
	}
	c[count + 1] = '\0';
	while (dec > 0)
	{
		n = (dec % 16);

		if (n >= 0 && n <= 9)
		{
			c[count] = ((char)(n + '0'));
		}

		else
		{
			c[count] = ((char)(n + 'W'));
		}
		count --;
		dec /= 16;
	}
	c[0] = '0';
	c[1] = 'x';

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}
	return (0);
}
