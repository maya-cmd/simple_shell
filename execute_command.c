#include "shell.h"

/**
 * command_execution - executes a command with a given arguement.
 *
 * @args_present: Array of command arguements.
 * @argv: Array of arguement passed to the main function.
 * @i : command input index
 * Return: exit status of the executed command.
 */
int command_execution(char **args_present, char **argv, int i)
{
	pid_t process_id;
	int status;
	char *full_path;

	full_path = path_finder(args_present[0]);
	if (!full_path)
	{
		error_printer(argv[0], args_present[0], i);
		free_arr(args_present);
		return (100);
	}

	process_id = fork();
	if (process_id == -1)
	{
		perror("Fork faied");
		free(full_path);
		free_arr(args_present);
		return (-1);
	}

	if (process_id == 0)

	{
		if (execve(full_path, args_present, environ) == -1)

		{
			perror("execution failed"); /* prints an error msg if the execve fails*/
			free(full_path);
			free_arr(args_present);
			exit(EXIT_FAILURE); /*exit the child process with an error code*/
		}
	}
	else
	{
		/* parent process*/
		waitpid(process_id, &status, 0); /* wait for the child process to finish*/
		{
			perror("waitpid failed");
			free(full_path);
			free_arr(args_present);
			return (-1);
		}
	}
	free_arr(args_present);
	free(full_path);

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status)); /* Return the exit status of exec command*/
	}
	else
	{
		perror("process_id failed");
		return (-1);
	}

}
