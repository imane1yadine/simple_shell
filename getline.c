#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *enami;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		enami = malloc(new_size);
		if (enami == NULL)
			return (NULL);

		return (enami);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	enami = malloc(sizeof(*ptr_copy) * new_size);
	if (enami == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = enami;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (enami);
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ena;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read_character(&c, &input, buffer);
		if (r == -1)
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		handle_buffer_resize(&buffer, &input);
	}

	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	ena = input;
	if (r != 0)
		input = 0;
	return (ena);
}

/**
 * read_character - Reads a character from the given stream
 * and updates the buffer.
 * @c: Pointer to the character variable.
 * @input: Pointer to the input counter.
 * @buffer: Buffer to store characters.
 *
 * Return: The result of the read operation.
 */

int read_character(char *c, ssize_t *input, char *buffer)
{
	int r = read(STDIN_FILENO, c, 1);

	if (r == -1 || (r == 0 && *input == 0))

		return (-1);
	return (r);
}

/**
 * handle_buffer_resize - Resizes the buffer if needed
 * and adds a character to it.
 * @buffer: Pointer to the buffer.
 * @input: Pointer to the input counter.
 */

void handle_buffer_resize(char **buffer, ssize_t *input)
{
	if (*input >= 120)
		*buffer = _realloc(*buffer, *input, *input + 1);

	(*buffer)[*input] = *c;
	(*input)++;
}
