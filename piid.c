#include <shell.h>

/**
 * Display the shell prompt.
 */

void display_prompt() {
    write(STDOUT_FILENO, "$ ", 2);
}

/**
 * Execute the given command.
 */

void execute_command(const char *command) {
    pid_t child_pid = fork();
    if (child_pid == -1) {
        /* Error handling for fork failure*/
        _exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process*/
        execlp(command, command, NULL);
        /* Error handling for execlp failure*/
        _exit(EXIT_FAILURE);
    } else {
        /* Parent process*/
        waitpid(child_pid, NULL, 0);
    }
}

/**
 * Main function for the shell.
 */

int main() {
    char user_input[MAX_INPUT_LENGTH];
    while (1) {
        display_prompt();
        if (read(STDIN_FILENO, user_input, sizeof(user_input)) == -1) {
            /* Handle Ctrl+D (end of file)*/
            write(STDOUT_FILENO, "\nGoodbye!\n", 10);
            break;
        }
        user_input[strcspn(user_input, "\n")] = '\0'; /* Remove newline*/
        if (strlen(user_input) == 0) {
            continue; /* Ignore empty input*/
        }
        execute_command(user_input);
    }
    return (0);
}
