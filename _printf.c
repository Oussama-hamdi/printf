#include "main.h"

/**
 * _print_char - writes a character to stdout
 * @args: argument list
 *
 * Return: 1
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);

	return (1);
}

/**
 * _print_string - writes a string to stdout
 * @args: argument list
 *
 * Return: number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);

	if (!format)
		return (1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _print_char(args);
					break;
				case 's':
					count += _print_string(args);
					break;
				case '%':
					putchar('%');
					count++;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
