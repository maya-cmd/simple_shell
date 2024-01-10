#include "shell.h"

/*
 * _strdup - duplicates a string in memory
 *
 * @s: the string to duplicate.
 *
 * Return: a pointer ti the allocated duplicate string,
 * or NULL if insufficient memory is available.
 */
char *_strdup(const char *s)
{
	char *ptr;
	int n, length = 0;

	/* checks if input string is null */
	if (s == NULL)
		return (NULL);

	/* calculates the lenght of the input string */
	while (*s != '\0')
	{
		length++;
		s++;
	}

	/* resets pointer to the beginning of the input string */
	s = s - length;

	/* allocates memory for duplicate strings*/
	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);

	/*copy char from input to newly allocated memory*/
	for (n = 0; n <= length; n++)
		ptr[n] = s[n];
	return (ptr); /*return the pointer ti the duplicated string*/
}
