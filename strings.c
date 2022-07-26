#include "main.h"

/**
*stringlen - returns length of string     Holberton hates us and we are too
*poor for standard lib
*@str: string to get length of
*Return: length
*/

int stringlen(char *str)
{
	int index = 0;

	if (str == NULL)
		return (0);
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

/**
*stringdup - duplicates and mallocs string
*@str: string to duplicate
*Return: pointer to new string
*/

char *stringdup(char *str)
{
	char *new_str;
	unsigned int index, len;

	if (str == NULL)
		return (NULL);

	len = stringlen(str);

	new_str = malloc((sizeof(char) * len) + 1);
	if (new_str == NULL)
		return (NULL);

	for (index = 0; index < len; index++)
	{
		new_str[index] = str[index];
	}
	return (new_str);
}

/**
*stringcpy - copies new string
*@dest: string to copy into
*@src: string to copy from
*Return: pointer to new string
*/

char *stringcpy(char *dest, const char *src)
{
	unsigned int len, i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
*stringcmp - compares 2 strings    Not the same as normal strcmp
*@s1: string 1 to compare
*@s2: string 2 to compate
*Return: 0 if same, -1 otherwise
*/

int stringcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

/**
*stringcat - concats src to dest
*@dest: dest string
*@src: source string
*Return: dest
*/

char *stringcat(char *dest, char *src)
{
	int s, d = stringlen(dest) + 1;

	for (s = 0; src[s] != '\0'; s++, d++)
	{
		dest[d] = src[s];
	}
	dest[d] = '\0';
	return (dest);
}
