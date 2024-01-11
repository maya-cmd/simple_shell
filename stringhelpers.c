#include "shell.h"
/**
 * _strdup - Duplicates a string in memory
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
/**
 * _strlen - Calculates how long a string is.
 * @str: The string.
 * Return: The string length
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}
/**
 * _strcpy - Makes a copy of a string.
 * @dest: The string destination
 * @src: The source of string used.
 * Return: A pointer to the copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == NULL || src == NULL)
	return (dest);
	while (src[k])
	{
	dest[k] = src[k];
	k++;
	}
	dest[k] = '\0';
	return (dest);
}

 /**
 * _strcat - Function concatenates two strings.
 * @dest: This is the destination string.
 * @src: The source string to be used.
 * Return: A pointer to the string that is concatenated
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
		return (dest);
	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
/**
 * _strcmp - Function compares two strings.
 * @str1: First string to be used
 * @str2: Second string to be used
 * Return: The result of the comparison (0 if equal, positive/negative otherwise).
 */
int _strcmp(char *str1, char *str2)
{
	int comp;

	comp = (int)*str1 - (int)*str2;

	while (*str1)
	{
		if (*str1 != *str2)
			break;

		str1++;
		str2++;
		comp = (int)*str1 - (int)*str2;

	}
	return (comp);
}
/**
 * _atoi - Changes a string to an integer.
 * @s: The string to in use.
 * Return: The integer representation of the string.
 */
int _atoi(char *s)
{
	int k, n = 0;
	for (k = 0; s[k]; k++)
	{
		n *= 10;
		n += (s[k] - '0');
	}
	return (n);
}
