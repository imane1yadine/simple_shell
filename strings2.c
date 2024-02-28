#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 * Return: A pointer to the newly allocated duplicate string,
 * or NULL if allocation fails.
 */
char *_strdup(const char *str)
{
	if (!str)
		return (NULL);

	size_t len = _strlen(str) + 1;
	char *dup = malloc(len);

	if (dup)
	{
		_strcpy(dup, str);
	}

	return (dup);
}

/**
 * starts_with - Check if a string starts with a specific prefix.
 * @str: The string to check.
 * @prefix: The prefix to check for.
 * Return: 1 if the string starts with the prefix, 0 otherwise.
 */
int starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return (0);
		prefix++;
		str++;
	}
	return (1);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if strings are equal, negative if s1 is less than s2,
 * positive if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
