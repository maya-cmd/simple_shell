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
int command_execution(char **args_present, char **argv, int i);
char *path_finder(char *args_preseent);
char *get_env_variable(char *var);
/* ===== stringhelpers.c ===== */
char *_strdup(const char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* ====== helpers.c ======*/
void free_arr(char **array);
void error_printer(char *n, char *command, int i);
char *_itoa(int i);
char *convert_to_string(int n);
void string_reverse(char *str, int len);
int positive_num(char *s);
int _atoi(char *s);

/* ====== shell_builtin.c ====== */
int shell_builtin(char *args_present);
void executing_builtin(char **args_present, char **argv, int *status, int i);
void shell_exit(char **args_present, char **argv, int *status, int i);
void printing_env(char **args_present, int *status);

#endif
