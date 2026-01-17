#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_percent - prints percent
 *
 * Return: int
 */

int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
