#include <shell.h>

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 * Return: A pointer to the concatenated string (dest).
 */
char *_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*temp)
		temp++;

	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}

	*temp = '\0';
	return (dest);
}

/**
 * _strcpy - Copy a string.
 * @dest: The destination string.
 * @src: The source string to copy.
 * Return: A pointer to the copied string (dest).
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}

	*temp = '\0';
	return (dest);
}

/**
 * _puts - Print a string to stdout.
 * @str: The string to print.
 */
void _puts(const char *str)
{
	write(1, str, _strlen(str));
}

/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
