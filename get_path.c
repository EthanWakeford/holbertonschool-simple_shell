#include "main.h"

/**
*get_env - gets an environment variable
*@name: name of env var to find
*Return: pointer to the variable, NULL on failure
*/

char *get_env(const char *name)
{
	int i, j;

	/*environ defined as extern char **environ in header*/
	for (i = 0; environ[i] != NULL; i++)
	{
		if (environ[i][0] == name[0])
		{
			for (j = 0; name[j] != '\0'; j++)
			/*checks and matches name with environ variable*/
			{
				if (environ[i][j] != name[j])
					break;
			}
			if (name[j] == '\0')
			/*if null byte then match is found*/
			{
				printf("%s\n", environ[i]);
				/*return string with name removed, (ex. just path)*/
				return (environ[i] + (j + 1));
			}
		}
	}
	/*no match found*/
	return (NULL);
}

/**
*get_path - gets the path of a command
*@command: command to find the path of
*Return: pointer to full path of command, NULL on failure
*/

char *get_path(char *command)
{
	char *path, *path_tok, *buffer;

	/*gets path and splits into tokens*/
	path = stringdup(get_env("PATH"));
	if (path == NULL)
		return (NULL);
	path_tok = strtok(path, ":");
	/*gets full path*/
	buffer = find_path(path_tok, command);
	free(path);
	return (buffer);
}

/**
*find_path - searches through the path to find where command exists
*@path_tok: token of each direcotry in PATH
*@command: command to find the path of
*Return: full path of command, NULL on failure
*/

char *find_path(char *path_tok, char *command)
{
	DIR *directory;
	struct dirent *file;
	char *buffer;

	while (path_tok != NULL)
	{
		directory = opendir(path_tok);
		if (directory == NULL)
		{
			closedir(directory);
			return (NULL);
		}

		/*moves through each file in directory*/
		while ((file = readdir(directory)) != NULL)
		{
			/*returns if matching file to command is found*/
			if (stringcmp(file->d_name, command) == 0)
			{
				closedir(directory);
				/* +2 bytes for null terminator and '/' */
				buffer = malloc(stringlen(path_tok) + 2 + stringlen(command));
				if (buffer == NULL)
					return (NULL);
				buffer = strcpy(buffer, path_tok);
				return (strcat(strcat(buffer, "/"), command));
			}
		}
		path_tok = strtok(NULL, ":");
		closedir(directory);
	}
	return (NULL);
}
