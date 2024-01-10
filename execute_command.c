#include "shell.h"

/**
 * command_execution - executes a command with a given arguement.
 *
 * @args_present: Array of command arguements.
 * @argv: Array of arguement passed to the main function.
 *
 * Return: exit status of the executed command.
 */
int command_execution(char *args_present, char **argv)
{
	pid_t process_id;
	int status;

	process_id = fork();
	if (process_id == 0)

	{
		if (execve(args_present, argv, environ) == -1)

		{
			perror("Execve failed"); /* prints an error msg if the execve fails*/
			exit(99); /*exit the child process with an error code*/
		}
	}
	else
	{
		/* parent process*/
		waitpid(process_id, &status, 0); /* wait for the child process to finish*/
	}
	return (WEXITSTATUS(status)); /* Return the exit status of exec command*/

}
