#include "main.h"

/**
*check_command - checks command if it exists and if it needs a path
*@command: command line input
*Return: 1 if first command is a path that exists, 0 if it needs a path
*-1 if command does not exist
*/

int check_command(char **command)
{
	struct stat st;

	if (stat(command[0], &st) == -1)
	{
		command[0] = get_path(command[0]);
		if (command[0] == NULL)
			return (-1);
		return (0);
	}
	return (1);
}
