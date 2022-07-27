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
	char *cmd_check;

	if (stat(command[0], &st) == -1)
	{
		cmd_check = get_path(command[0]);
		if (cmd_check == NULL)
			return (-1);
		command[0] = cmd_check;
		return (0);
	}
	return (1);
}
