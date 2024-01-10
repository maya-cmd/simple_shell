#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>

#define  partitioner " \t\n"
extern char **environ;

char *read_command_entered(void);
char **handling_command_entered_args(char *command_entered);
int command_execution(char *args_present, char **argv);

/* ===== stringhelpers.c ===== */
char *_strdup(const char *str);

#endif
