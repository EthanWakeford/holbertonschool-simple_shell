#include "main.h"

/**
*stringlen - returns length of string
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
		inddex++;
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
