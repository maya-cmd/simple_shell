#include "shell.h"

/*
 * handling_command_entered_args - Tokenize then command entered
 * into arguements.
 *
 * @command_enetred: the command entered by user.
 *
 * Return: array of pointers ti the tokenized arguements.
 */

char **handling_command_entered_args(char *command_entered)
{
	char *token = NULL;
	int i = 0;
	int args_counter = 0;
	char *temp = NULL;
	char **args_present = NULL;


	/*check if input is NULL*/
	if (!command_entered)
		return (NULL);

	/*duplicate command for tekenization*/
	temp = _strdup(command_entered);
	token = strtok(temp, partitioner);

	/*check if token is null*/
	if (token == NULL)

	{
		free(command_entered), temp = NULL;
		free(temp), temp = NULL;

		return (NULL);
	}

	/*count num of arguements*/
	while (token)

	{
		args_counter++;
		token = strtok(NULL, partitioner);

	}
	free(temp);
	temp = NULL;

	args_present = malloc(sizeof(char *) * (args_counter + 1));

	if (!args_present)

	{
		free(command_entered);
		return (NULL);

	}

	/*tokenize and store arguement in an array*/
	token = strtok(command_entered, partitioner);
	while (token)

	{
		args_present[i] = _strdup(token);
		token = strtok(NULL, partitioner);

		i++;

	}

	args_present[i] = NULL;

	free(command_entered);
	return (args_present);
}
