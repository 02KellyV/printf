#include "holberton.h"
#include <stdarg.h>

/**
 * print_ptr - print_base16_upper_lower
 * @arg: va_list parameter
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

	if (!dec)
	{
		_puts("(neil)");
		return (5);
	}

	while (buffr)
	{
		buffr /= 16;
		count++;
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
		count--;
		dec /= 16;
	}
	c[0] = '0';
	c[1] = 'x';

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}
	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments from _printf
 * Return: length of the printed string
 */

int print_rot13(va_list arg)
{
        register short i, j;
        char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
        char *s = va_arg(arg, char *);

        for (j = 0; s[j]; j++)
        {
                if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
                        _putchar(s[j]);
                else
                {
                        for (i = 0; i <= 52; i++)
                                if (s[j] == rot13[i])
                                        _putchar(ROT13[i]);
                }
        }
        return (j);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list arg)
{
	int i = 0;
	int j;
	char *s = va_arg(arg, char *);

	if (!s)
	{
		s = "(null)";
	}

	while (s[i])
	{
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
	}

	return (i);
}
