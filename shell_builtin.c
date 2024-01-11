#include "shell.h"
/**
 * printing_env - Executes the  built-in command 'env'.
 * @args_present: The env command and its arguments.
 * @status: The exit status of the last command.
 */
void printing_env(char **args_present, int *status)
{
	int k;

	for (k = 0; environ[k]; k++)
	{
	write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
	write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(args_present);
	(*status) = 0;
}
/**
 * executing_builtin - Executes a built-in command.
 * @args_present: The built-in command and its arguments.
 * @argv: Command line arguments present.
 * @status: The exit status of the last command.
 * @i: command input index.
 */
void executing_builtin(char **args_present, char **argv, int *status, int i)
{
	if (_strcmp(args_present[0], "exit") == 0)
	shell_exit(args_present, argv, status, i);

	else if (_strcmp(args_present[0], "env") == 0)
	printing_env(args_present, status);
}
/**
 * shell_builtin - Confirms if user input is a built-in shell command.
 * @args_present: User input to be  checked.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int shell_builtin(char *args_present)
{
	char *builtins[] = {
	    "exit", "env", "setenv",
	    "cd", NULL};
	int k;

	for (k = 0; builtins[k]; k++)
	{
	if (_strcmp(args_present, builtins[k]) == 0)
		return (1);
	}
	return (0);
}
/**
 * shell_exit - Executes the 'exit' built-in command.
 * @args_present: The exit command used.
 * @argv: The command line arguments.
 * @status: The exit status of command enteredd.
 * @i: The index of the command used.
 */
void shell_exit(char **args_present, char **argv, int *status, int i)
{
	int exit_val = (*status);
	char *k, output[] = ": exit: Illegal number: ";

	if (args_present[1])
	{
		if (positive_num(args_present[1]))
		{
			exit_val = _atoi(args_present[1]);
		}
		else
		{
		    k = _itoa(i);
		    write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		    write(STDERR_FILENO, ": ", 2);
		    write(STDERR_FILENO, k, _strlen(k));
		    write(STDERR_FILENO, output, _strlen(output));
		    write(STDERR_FILENO, args_present[1], _strlen(args_present[1]));
		    write(STDERR_FILENO, "\n", 1);

		    free(k);
		    free_arr(args_present);
		    (*status) = 2;
		    return;
		}
	}
	free_arr(args_present);

	exit(exit_val);
}
