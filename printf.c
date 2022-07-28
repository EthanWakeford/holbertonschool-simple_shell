#include "printf.h"

/**
*get_func - finds the correct function to run
*@conv_spec: conversion specifier to match with correct function
*Return: pointer to correct print function, NULL if no match found
*/

int (*get_func(char conv_spec))(va_list, int)
{
	int i = 0;
	type_t get_type[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_dec},
		{'i', print_dec},
		{'\0', NULL}
	};

	if (!conv_spec)
		exit(100);
	for (i = 0; get_type[i].form_match != conv_spec; i++)
	{
		if (get_type[i].form_match == '\0')
			return (NULL);
	}
		return (get_type[i].func);
}

/**
*_printf - prints out a line
*@format: format to print out
*Return: count of printed characters on success, a negative number on failure
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int i, count = 0;
	int (*print)(va_list, int);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			print = get_func(format[i]);
			if (print == NULL)
			{
				if (format[i] != '%')
					count += _putchar('%');
				count += _putchar(format[i]);
			}
			else
				count = print(ap, count);
		}
		else
			count += _putchar(format[i]);
		if (count == -1)
			return (count);
	}
	va_end(ap);
	return (count);
}

/**
 * int_len - gets # of digits in a number
 * @c: digit to get length of
 * Return: # of digits in number
 */

int int_len(int c)
{
	int count = 0;

	if (c == 0)
		return (count += 1);
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}
