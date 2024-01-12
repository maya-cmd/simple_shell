#include "shell.h"
/**
 * _itoa - Changes an integer to string.
 * @i: The integer to be used in conversion.
 * Return: The string representation of the integer.
 */
char *_itoa(int i)
{
	char buff[22];
	int k = 0;

	if (i == 0)
		buff[k++] = '0';
	else
	{
		/* Convert an integer to a string */
		while (i > 0)
		{
			buff[k++] = (i % 10) + '0';
			i /= 10;
		}
	}

	buff[k] = '\0';
	string_reverse(buff, k);

	return (_strdup(buff));
}
/**
 * error_printer - Function error message to standard error.
 * @n: The name of the program.
 * @command: The command bringing the error.
 * @i: The index of the command in use.
 */
void error_printer(char *n, char *command, int i)
{
	char *k;
	char output[] = ": not found\n";

	k = _itoa(i);

	write(STDERR_FILENO, n, _strlen(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, k, _strlen(k));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, output, _strlen(output));

	free(k);
}
/**
 * string_reverse - Function reverses a string
 * @s: String reversed
 * @length: How long the reversed string is
 */
void string_reverse(char *s, int length)
{
	char temporary;
	int beg = 0;
	int ending = length - 1;

	while (beg < ending)
	{
		temporary = s[beg];
		s[beg] = s[ending];
		s[ending] = temporary;
		beg++;
		ending--;
	}
}


/**
 * free_arr - Function frees an array of strings that's 2D.
 * @array: The array used.
 */
void free_arr(char **array)
{
	int n;

	if (!array)
		return;

	for (n = 0; array[n]; n++)
	{
		free(array[n]);
		array[n] = NULL;
	}

	free(array);
	array = NULL;
}
/**
 * positive_num - Confirms if it's a positive number in use
 * @s: String to be used
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int positive_num(char *s)
{
	int n;

	if (!s)
		return (0);

	for (n = 0; s[n]; n++)
	{
		if (s[n] < '0' || s[n] > '9')
			return (0);
	}

	return (1);
}
