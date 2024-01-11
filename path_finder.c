#include "shell.h"
/**
 * path_finder - Looks for the full path of a command.
 * @args_present: The command to find path for.
 *
 * Return: A dynamically allocated string representing the full path,
 *         or NULL if the command is not found or encounters an error.
 */
char *path_finder(char *args_present)
{
	char *shell_path, *full_path, *path_dir;
	int n;
	struct stat s;

	for (n = 0; args_present[n]; n++)
	{
		if (args_present[n] == '/')
		{
			if (stat(args_present, &s) == 0)
				return (_strdup(args_present));
			return (NULL);
		}
	}
	shell_path = get_env_variable("PATH");
	if (!shell_path)
		return (NULL);

	for (path_dir = strtok(shell_path, ":"); path_dir; path_dir = strtok(NULL, ":"))
	{
		full_path = malloc(_strlen(path_dir) + _strlen(args_present) + 2);
		if (!full_path)
		{
			free(shell_path);
			return (NULL);
		}

		_strcpy(full_path, path_dir);
		_strcat(full_path, "/");
		_strcat(full_path, args_present);

		if (stat(full_path, &s) == 0)
		{
			free(shell_path);
			return (full_path);
		}
		free(full_path);
	}

	free(shell_path);
	return (NULL);
}

