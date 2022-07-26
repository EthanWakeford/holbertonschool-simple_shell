#include "main.h"

/**
*main - a simple shell
*@argc: arg count
*@argv: vector
*@envp: environment pointer
*Return: always zero
*/

int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize;
	int check;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("($) ");
		getline(&buffer, &bufsize, stdin);

		if (stringcmp(buffer, "exit\n") == 0)
			break;
		command = token(buffer);
		if (command == NULL)
			continue;
		check = check_command(command);
		if (check == -1)
		{
			printf("invalid command\n");
			continue;
		}
		fwe(command);
		if (check == 0)
			free(command[0]);
		free(command);
	}
	free(buffer);
	return (0);
}
