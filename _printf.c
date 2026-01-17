#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output
 * @format: format string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args,format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1,&format[i],1);
			count++;
			i++;
		}
		else
		{
			i++;

			if (format[i] == '\0')
				return (-1);
			if (format[i] =='c')
				count+=print_char(args);
			else if (format[i] == 's')
				count+=print_string(args);
			else if (format[i] == '%')
				count+=print_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(args);
			else
			{
				write(1,"%",1);
				write(1,&format[i],1);
				count+=2;
			}
			i++;
		}
	}
	va_end(args);
	return(count);

}
