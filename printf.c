#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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
			_puts(convert_to(d, 10));
			break;
		case 'o':
			i = va_arg(arg, unsigned int);
			_puts(convert_to(i, 8));
			break;
		case 's':
			s = va_arg(arg, char *);
			_puts(s);
			break;
		case 'x':
			i = va_arg(arg, unsigned int);
			_puts(convert_to(i, 16));
			break;
	}
	return (cont_characters);
}

int _printf(const char *format, ...)
{
	const char *string;
	int cont_characters = 0, i = 0;
	va_list arg;

	va_start(arg, format);
	string = format;
	while (i < _strlen((char *)string) && *string != '\0')
	{
		char aux = string[i];
		if (aux == '%')
		{
			i++;
			aux = string[i];
			if (aux != '%')
			{
				_switch(aux, arg);
				i++;
				aux = string[i];
			}
		}
		_putchar(aux);
		i++;
	}
	va_end(arg);
	return (cont_characters);
}
