#include "shell.h"

/**
 * main - entry point for all shell program.
 *
 * @ac: number of command line arguements
 * @argv: array of command line arguement strings.
 *
 * Return: the exit status for shell program.
 *
 */

int main(int ac, char **argv)
{
	char *command_entered = NULL, **args_present = NULL;
	int exit_code = 0;
	(void)ac;/*unused parameter*/

	while (1)
	{
		command_entered = read_command_entered();/*read user input*/
		if (command_entered == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);/*print a lew line if using terminal*/
			free(command_entered);/*free allocated memory*/
			return (exit_code);/*return exit code*/
		}
		args_present = handling_command_entered_args(command_entered);
		if (!args_present)
			continue;/*skip the rest of the loop if tokenization fails*/


		exit_code = command_execution(args_present, argv);/*exec command*/

	}
}
