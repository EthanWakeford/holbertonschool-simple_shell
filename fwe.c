#include "main.h"
/**
 * fwe - fork, wait, execute.
 * @command: input command.
 *
 * Return: 0 on success.
 */
int fwe(char **command)
{
	pid_t process;

	process = fork();

	if (process == 0)
	{
		if(execve(command[0], command, NULL) == -1)
		{
			printf("failed to execute");
			exit(100);
		}
	}
	else 
		wait(NULL);

	return(0);
}
