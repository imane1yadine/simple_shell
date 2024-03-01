#include "shell.h"

/**
 * main - Simple Shell main function
 * @argv: arguments
 * @argc: count of arguments
 *
 * Description: The main function of a simple shell. It reads input lines,
 * tokenizes them and executes the corresponding commands using the _execute
 * function.
 *
 * Return: 0 always.
 */
int main(int argc, char **argv)
{
	char **command = NULL;
	char *line = NULL;
	int status = 0;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = tokenizer(line);
		if (command == NULL)
			continue;

		status = _execute(command, argv);
	}
}

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 *         Returns NULL if an error occurs or if the input is empty.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	write(STDOUT_FILENO "$", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * tokenizer - Tokenizes a string into an array of strings using strtok.
 *
 * @line: The input string to be tokenized.
 * Return: A dynamically allocated array of strings representing the tokens.
 *         Returns NULL if the input string is NULL
 *         or if memory allocation fails.
 */
char **tokenizer(char *line)
{
	char *token = NULL, tmp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (line == NULL)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (command == NULL)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}

/**
 * _execute - Executes a command with arguments using fork and execve.
 *
 * @command: A pointer to the array of strings representing the command
 *           and its arguments.
 * @argv: A pointer to the array of strings representing the program
 *        and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **argv)
{
	pid_t momo;

	if (momo == 0)
	{
		if (exexve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearr2d(command);
		}
	}
	else
	{
		waitpid(momo, &status, 0)
			freearr2d(command);
	}
	return (WEXITSTATUS(status));
}

/**
 * freearr2d - Frees the memory allocated for
 * a two-dimensional array of strings.
 *
 * @arr: A pointer to the array of strings.
 *
 * Description: This function frees the memory allocated for a two-dimensional
 * array of strings. It takes a pointer to the array of strings as a parameter.
 *
 * Return: void
 */
void freearr2d(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}
