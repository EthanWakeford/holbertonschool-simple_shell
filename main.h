#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

int strnglen(char *str);
char *stringdup(char *str);
char *stringcpy(char *dest, char *src);

#endif
