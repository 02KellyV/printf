#include "holberton.h"
/**
 *_printf - printf
 *@format: const char pointer
 *Description: this functions implement some functions of printf
 *Return: num of characteres printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int cont = 0, i = 0;
	va_list arg;

	if (!format)
	{
		return (-1);
	}

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
				cont = cont + function_manager(aux, arg);
				i++;
				aux = string[i];
			}
		}
		_putchar(aux);
		cont++;
		i++;
	}
	va_end(arg);
	return (cont);
}
