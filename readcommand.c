#include "shell.h"
/**
 * read_command_entered - Function reads input from user
 *
 * Return: A pointer to the read line.
 */
#include "shell.h"

char *read_command_entered(void)
{

	size_t command_length = 0;
	ssize_t command_read;
	char *command_entered = NULL;

	if (isatty(STDIN_FILENO) == 1)

		write(STDOUT_FILENO, "shellshell$ ", 12);

	command_read = getline(&command_entered, &command_length, stdin);


	if (command_read == -1)
	{

		free(command_entered);
		return (NULL);

	}
	return (command_entered);



}
