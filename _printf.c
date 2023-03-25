#include "main.h"

/**
 * _printf - print a formated string
 * @format: A string containing all the desired characters
 * Return: length of the printed characters
 */

int _printf(const char *format, ...)
{
	int count;

	print_t c[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};

	va_list args;

	if (!format)
		return (1);

	va_start(args, format);
	count = parser(format, c, args);
	va_end(args);
	return (count);
}
