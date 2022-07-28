#include "printf.h"

/**
 * print_dec - prints decimal number
 * @ap: int from ap_list
 * @count: total count of _printf function
 * Return: total of  count plus int
 */

int print_dec(va_list ap, int count)
{
	int c = va_arg(ap, int);
	int last;

	count += int_len(c);
	if (c < 0)
	{
		_putchar('-');
		last = -1 * (c % 10);
		c = -1 * (c / 10);
		count++;
		if (c != 0)
			dec_print(c);
		_putchar('0' + last);
	}
	else
		dec_print(c);
	return (count);
}

/**
 * dec_print - prints an int passed by print_dec
 * @c: int to be printed
 * Return: 0.
 */

int dec_print(int c)
{
	if (c > 9)
	{
		int a = c / 10;

		c -= 10 * a;
		dec_print(a);
	}
	_putchar('0' + c);
	return (0);
}

/**
 * print_char - prints a character
 * @ap: character to be printed
 * @count: total count of _printf
 * Return: count of 1 or -1 if character is NULL.
 */

int print_char(va_list ap, int count)
{
	char c;

	c = (char)va_arg(ap, int);
	(write(1, &c, 1));
	return (count += 1);
}

/**
 * print_str - returns a string
 * @ap: string to be printed
 * @count: total count of _printF
 * Return: total count plus length of the string,
 * if string is NULL return -1.
 */

int print_str(va_list ap, int count)
{
	char *c;
	int i;

	c = va_arg(ap, char*);
	if (c == NULL)
	{
		c = "(null)";
	}
	for (i = 0; c[i] != '\0'; i++)
	{
		(write(1, &c[i], 1));
	}
	return (count += stringlen(c));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
