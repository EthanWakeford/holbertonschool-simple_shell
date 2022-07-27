# Holberton Shell Project
## Files

 - main.h - A header file containing the  various libraries, functions, and structures called in the program.
 - strings.c - A file containing prototype functions for various string functions, such as (strcpy, strcmp, strdup, ...)
 - shell.c - A file containing functions that gets takes input  commands and calls various outside functions to check and run the input.
 - token.c - A file containing functions that splits an input from the user into single commands and counts each command.
 - check_command.c - A file containing a function that checks to see if the input command is valid and if it requires a path.
 - fwe.c - A file that contains functions that splits the process in to a child and parent, the child runs the command the parent continues the shell.
 - get_path.c - A file containing functions that prints environmental variables, as well as finding and printing the path of a given command.
 
 ## Usage
 ### interactive mode
1. Type `./hsh`in the command line to open run the shell command
2. Shell will prompt the User for input.
Output: `($)`
3. Type a command into shell. Ex. `ls -l /usr`
Output: 
total 16
drwxr-xr-x 1 root root 4096 Jul  2 10:38 bin
drwxr-xr-x 2 root root    6 Apr 15  2020 games
drwxr-xr-x 1 root root 4096 Jul  2 10:39 include
drwxr-xr-x 1 root root  134 Jul  2 10:37 lib
drwxr-xr-x 1 root root 4096 Mar 29 18:59 lib32
drwxr-xr-x 1 root root   34 Mar 29 19:08 lib64
drwxr-xr-x 1 root root   95 Mar 29 19:09 libexec
drwxr-xr-x 1 root root 4096 Mar 29 18:59 libx32
drwxr-xr-x 1 root root   19 Mar 16 10:07 local
drwxr-xr-x 1 root root   28 Jul  2 10:35 sbin
drwxr-xr-x 1 root root  133 Mar 29 19:07 share
drwxr-xr-x 2 root root    6 Apr 15  2020 src
4. Shell parses the input string into commands and executes them accordingly.
5. Shell prompts the user for another input command.
###  Non-Interactive mode
1. Type `./hsh | "command input"` into command line.
Ex. `./hsh | ls -l /usr`
Output: total 16
drwxr-xr-x 1 root root 4096 Jul  2 10:38 bin
drwxr-xr-x 2 root root    6 Apr 15  2020 games
drwxr-xr-x 1 root root 4096 Jul  2 10:39 include
drwxr-xr-x 1 root root  134 Jul  2 10:37 lib
drwxr-xr-x 1 root root 4096 Mar 29 18:59 lib32
drwxr-xr-x 1 root root   34 Mar 29 19:08 lib64
drwxr-xr-x 1 root root   95 Mar 29 19:09 libexec
drwxr-xr-x 1 root root 4096 Mar 29 18:59 libx32
drwxr-xr-x 1 root root   19 Mar 16 10:07 local
drwxr-xr-x 1 root root   28 Jul  2 10:35 sbin
drwxr-xr-x 1 root root  133 Mar 29 19:07 share
drwxr-xr-x 2 root root    6 Apr 15  2020 src
2. Shell opens and runs the given command "ls -l /usr", before closing and returning dormant.
##  Notable Functions
**check_command** - a function that checks to see if the given command exists and is valid.
**token** - a function that parses a string into commands
**get-env** - a function that prints the environmental variables of a given command.
**get_path** - a function that finds and prints a given commands path.
**fwe** - a function that forks the command process, running the child process to execute the given command, then running the parent process to keep the shell running.

> Written with [StackEdit](https://stackedit.io/).
