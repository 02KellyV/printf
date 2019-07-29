#include "holberton.h"
#include <stdarg.h>
/**
 *function_manager - function manager
 *@c: character to find
 *@arg: va_list type
 *Description: This function call other functions
 * when the character is found
 *Return: count of printed characters
 */
int function_manager(char c, va_list arg)
{
	int cont = 0;

	cont = _switch(c, arg);
	return (cont);
}

int _switch(char c, va_list arg)
{
	int cont_characters = 0, d = 0;
	unsigned int i;
	char *s;

	switch (c)
	{
		case 'c':
			i = va_arg(arg, int);
			_putchar(i);
			break;
		case 'd':
			d = va_arg(arg, int);
			if (d < 0)
			{
				d = -(d);
				_putchar('-');
			}
			_puts(convert_to("0123456789ABCDEF", d, 10));
			break;
		case 'o':
			i = va_arg(arg, unsigned int);
			_puts(convert_to("0123456789ABCDEF", i, 8));
			break;
		case 's':
			s = va_arg(arg, char *);
			_puts(s);
			break;
		case 'x':
			i = va_arg(arg, unsigned int);
			_puts(convert_to("0123456789ABCDEF", i, 16));
			break;
	}
	return (cont_characters);
}
