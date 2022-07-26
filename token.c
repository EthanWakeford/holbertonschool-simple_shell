#include "main.h"
/**
 * count - counts number of tokenized arguments in string.
 * @buffer: untokenized input string.
 *
 * Return: argument count.
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
			arg_count++;
			while (buffer[i] && buffer[i] != ' ')
				i++;
		}
	}
	return(arg_count);
}
/**
 * token - split a string into idividual arguments.
 * @buffer: input string.
 * 
 * Return: tokenized arguments.
 */
char **token(char *buffer)
{
	char **command;
	char *delimeter = " \n";
	size_t token_count;
	int i;
	
	token_count = count(buffer)

	command = malloc(sizeof(*command) * (token_count + 1))
	if (command == NULL)
	{
		return(NULL);
	}

	token = strtok(buffer, delimeter);
	
	i = 0;
	while (token != NULL)
	{
		command[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	command[i] = NULL;
	return(command)
}
