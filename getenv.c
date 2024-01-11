#include "shell.h"
/**
 * get_env_variable - Looks for environmental variable
 * @var: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_env_variable(char *var)
{
	char *temp, *val, *key, *env_value;
	int k;

	for (k = 0; environ[k]; k++)
	{
		temp = _strdup(environ[k]);

		key = strtok(temp, "=");

		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");

			env_value = _strdup(val);

			free(temp);
			return (env_value);
		}

		free(temp), temp = NULL;
	}

	return (NULL);
}
