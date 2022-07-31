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
#include <errno.h>
#include <ctype.h>

extern char **environ;

void run(int run_count, char *buffer, char **argv, char **envp);
char **token(char *buffer);
int count(char *buffer);
int fwe(char **command, char **envp);
int stringlen(char *str);
char *stringdup(char *str);
char *stringcpy(char *dest, const char *src);
int stringcmp(char *s1, char *s2);
char *stringcat(char *dest, char *src);
char *get_env(const char *name);
char *get_path(char *command);
char *find_path(char *path_tok, char *command);
int check_command(char **command);

#endif
