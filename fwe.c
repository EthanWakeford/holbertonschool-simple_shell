#include "main.h"
/**
 * fwe - fork, wait, execute.
 * @command: input command.
 * @envp: environment pointer
 * Return: 0 on success.
 */
int fwe(char **command, char **envp)
{
	pid_t process;

	process = fork();

	if (process == -1)
	{
		perror("Error");
		return (-1);
	}
	if (process == 0)
	{
		if (execve(command[0], command, envp) == -1)
		{
			printf("failed to execute");
			exit(100);
		}
	}
	else
		wait(NULL);

	return (0);
}
