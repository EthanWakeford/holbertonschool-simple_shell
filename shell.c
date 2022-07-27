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
	int run_count = 0;

	(void)argc;

	/*checks for interactive vs non-interactive mode, runs accordingly*/
	if (isatty(STDIN_FILENO) != 1)
	{
		while (getline(&buffer, &bufsize, stdin) != EOF)
		{
			run_count++;
			run(run_count, buffer, argv, envp);
		}
	}
	else
	{
		while (1)
		{
			printf("($) ");
			if (getline(&buffer, &bufsize, stdin) == EOF)
			{
				printf("\n");
				break;
			}
			if (strcmp(buffer, "exit\n") == 0)
				break;
			if (buffer[0] == '\n')
				continue;
			run_count++;
			run(run_count, buffer, argv, envp);
		}
	}
	free(buffer);
	return (0);
}

/**
*run - runs the shell one time through
*@buffer: input from user or file
*@envp: environment pointer
*/

void run(int run_count, char *buffer, char **argv, char **envp)
{
	char **command;
	int check;

	command = token(buffer);
	if (command == NULL)
		return;
	check = check_command(command);
	if (check == -1)
	{
		printf("%s: %d: %s: not found\n", argv[0], run_count, command[0]);
		free(command);
		return;
	}
	fwe(command, envp);
	if (check == 0)
		free(command[0]);
	free(command);
	return;
}
