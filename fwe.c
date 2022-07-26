#include "main.h"
/**
 *
 *
 */
int fwe(char **argv)
{
	pid_t process;

	process = fork();

	if (process == 0)
	{
		if(execve(arv[0], argv, env) == -1)
		{
			_printf("failed to execute");
			exit(100);
		}
	}
	else 
		wait(NULL);

	return(0);
}
