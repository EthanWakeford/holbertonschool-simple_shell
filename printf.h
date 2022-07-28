#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
*struct type - matches format specifier and function pointer
*@form_match: format specifier to match
*@func: function to run
*/

typedef struct type
{
	char form_match;
	int (*func)(va_list, int);
} type_t;

int (*get_func(char conv_spec))(va_list, int);
int _printf(const char *format, ...);
int print_dec(va_list ap, int count);
int dec_print(int c);
int print_char(va_list ap, int count);
int print_str(va_list ap, int count);
int _putchar(char c);
int int_len(int c);

#endif
