#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>


/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;



int _printf(const char *format, ...);
int _putchar(char c);
int parser(const char *format, print_t p[], va_list arg_list);

#endif /* MAIN_H */
