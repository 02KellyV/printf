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
	int cont = 0;
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	cont = loop_format(arg, string);

	va_end(arg);
	return (cont);
}
/**
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characteres printed
 */
int loop_format(va_list arg, const char *string)
{
	int len = 0, i = 0, flag = 0, cont_fm = 0, cont = 0;

	len = _strlen((char *)string);
	while (i < len && *string != '\0')
	{
		char aux = string[i];

		if (aux == '%')
		{
			i++;
			flag++;
			aux = string[i];
			if (aux == '%')
			{
				flag++;
			} else
			{
				cont_fm = call_function_manager(aux, arg);
				if (cont_fm != 0)
				{
					i++;
					aux = string[i];
					cont = cont + cont_fm;
				}
			}
		}
		if (flag == 2 && aux == '%')
		{
			_putchar('%');
			flag = 0;
		} else
		{
			_putchar(aux);
		}
		cont++;
		i++;
	}
	return (cont);
}
/**
 * call_function_manager - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Description: This function call function manager
 *Return: num of characteres printed
 */

int call_function_manager(char aux, va_list arg)
{
	int cont = 0;

	cont = function_manager(aux, arg);
	return (cont);
}
