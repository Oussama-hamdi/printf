#include "main.h"

/**
 * _print_char - writes a character to stdout
 * @args: argument list
 * Return: 1
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * _print_string - writes a string to stdout
 * @args: argument list
 * Return: number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	if (!str)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * _print_int - writes an integer to stdout
 * @args: argument list
 * Return: number of characters printed
 */
int _print_int(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += _print_int(num / 10);
	_putchar(num % 10 + '0');
	count++;
	return (count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
				count += _print_char(args);
			else if (*format == 's')
				count += _print_string(args);
			else if (*format == 'd' || *format == 'i')
				count += _print_int(va_arg(args, int));
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
