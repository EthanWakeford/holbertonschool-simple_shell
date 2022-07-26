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
	size_t bufsize;

	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO) != 1)
	{
		while (getline(&buffer, &bufsize, stdin) != EOF)
		run(buffer, envp);
	}
	else
	{
		while (1)
		{
			printf("($) ");
			if (getline(&buffer, &bufsize, stdin) == -1)
			{
				printf("\n");
				break;
			}
			if (strcmp(buffer, "exit\n") == 0)
				break;
			if (buffer[0] == '\n')
				continue;
			run(buffer, envp);
		}
	}
	free(buffer);
	return (0);
}

void run(char *buffer, char **envp)
{
	char **command;
	int check;

	command = token(buffer);
	if (command == NULL)
		return;
	check = check_command(command);
	if (check == -1)
	{
		printf("invalid command\n");
		return;
	}
	fwe(command, envp);
	if (check == 0)
		free(command[0]);
	free(command);
}
