#include "main.h"
#include "printf.h"

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
	int i;

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
			_printf("($) ");
			if (getline(&buffer, &bufsize, stdin) == EOF)
			{
				printf("\n");
				break;
			}
			if (stringcmp(strtok(buffer, " \t"), "\n") == 0)
				continue;
			if (stringcmp(strtok(buffer, " \n\t"), "exit") == 0)
			{
				free(buffer);
				exit(errno);
			}
			run_count++;
			run(run_count, buffer, argv, envp);
		}
	}
	free(buffer);
	return (0);
}

/**
*run - runs the shell one time through
*@run_count: count of times things have been entered
*@buffer: input from user or file
*@argv: argument vector of call to function
*@envp: environment pointer
*/

void run(int run_count, char *buffer, char **argv, char **envp)
{
	char **command;
	int check, i;

	for (i = 0; buffer[i]; i++)
	{
		if (isspace(buffer[i]) == 0)
			return;
	}
	command = token(buffer);
	if (command == NULL)
		return;
	
	check = check_command(command);
	if (check == -1)
	{
		_printf("%s: %d: %s: ", argv[0], run_count, command[0]);
		perror("");
		free(command);
		return;
	}
	fwe(command, envp);
	if (check == 0)
		free(command[0]);
	free(command);
}
