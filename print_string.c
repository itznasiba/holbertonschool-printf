#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - prints a string
 * @arg: arguments
 *
 * Return: the number of elements printed
 */

int print_string(va_list args)
{
	char *s;
	int len = 0;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";

	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}
