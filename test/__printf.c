#include "main.h"

/**
 * _printf - print a formated string
 * @format: A string containing all the desired characters
 * Return: length of the printed characters
 */

int _printf(const char *format, ...)
{
	int count;

	va_list args;

	if (!format)
		return (1);

	va_start(args, format);
	count = vprintf(format, args);
	va_end(args);
	return (count);
}
