#include "main.h"
/**
 *
 *
 */
int count(char *buffer)
{
	size_t arg_count = 0;
	int i = 0 ;
	while (buffer[i])
	{
		if (buffer[i] == ' ')
			i++;
		else
		{
			count++;
			while (buffer[i] && buffer[i] != ' ')
				i++;
		}
	}
	return(count);
}
char **token(char *buffer)
{
	char **argv;
	char *token;
	char *delimeter = " \n";
	size_t token_count;
	int i = 0;
	
	token_count = count(buffer)
	argv = malloc(sizeof(*argv) * (token_count + 1))
	token = strtok(buffer, delimeter);

	while (token != NULL)
	{
		argv[i] = token;
		if (argv == NULL)
		{
			free(argv);
			free(buffer);
			return(NULL);
		}
		token = strtok(NULL, delimeter);
		i++;
	}
	argv[i] = NULL;
	return(argv)
}
