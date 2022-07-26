#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

extern char **environ;

int stringlen(char *str);
char *stringdup(char *str);
char *stringcpy(char *dest, const char *src);
int stringcmp(char *s1, char *s2);
char *get_env(const char *name);
char *get_path(char *command);
char *find_path(char *path_tok, char *command);

#endif
