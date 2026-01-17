#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number_recursive - prints an integer recursively
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number_recursive(int n)
{
	char c;
	int count = 0;

	if (n / 10)
		count += print_number_recursive(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}

/**
 * print_number - prints an integer from va_list
 * @args: va_list containing the integer
 *
 * Return: number of characters printed
 */
int print_number(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		if (n == -2147483648) /* INT_MIN edge case */
		{
			write(1, "2147483648", 10);
			return (count + 10);
		}
		n = -n;
	}

	count += print_number_recursive(n);
	return (count);
}
