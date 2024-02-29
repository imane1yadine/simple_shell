#include <shell.h>


/**
 * display_prompt - Displays the shell prompt
 *
 * This function is responsible for
 * displaying the shell prompt to the user.
 * The prompt is a simple string, such as "#cisfun$ ".
 */

void display_prompt()
{
	char prompt[] = "#cisfun$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	write(STDOUT_FILENO, " ", 1);  /* Add a space after the prompt*/
}

/**
 * execute_command - Executes a command using fork and execve
 * @command: The command to be executed
 */

void execute_command(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command, NULL, NULL) == -1)
		{
			char error_msg[] = "shell: command not found\n";
			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		char error_msg[] = "shell: fork failed\n";
		write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
	}
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - Entry point for the simple shell
 *
 * This function serves as the entry point for
 * the simple shell program.
 * It initializes necessary variables
 * and enters the main loop to wait for
 * user input and execute commands.
 *
 * Return: 0 on successful execution.
 */

int main()
{
	char input[MAX_INPUT];

	while (1)
	{
		display_prompt();

		if (read(STDIN_FILENO, input, MAX_INPUT) <= 0)
		{
			/* Handle Ctrl+D (EOF)*/
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/*Remove the trailing newline character*/
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			/* Exit the shell*/
			break;
		}

		execute_command(input);
	}

	return (0);
}
