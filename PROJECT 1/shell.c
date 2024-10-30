#define _POSIX_C_SOURCE 200112L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128
extern char **environ;

const char delimiters[] = " \n\t";

void tokenize(char* command_line, char** arguments) {
    int arg_index = 0;
    char* token = strtok(command_line, delimiters);
    while (token != NULL) {
        if (token[0] == '$') { // If the token starts with $, treat as environment variable.
            token = getenv(token + 1);
        }
        arguments[arg_index++] = token;
        token = strtok(NULL, delimiters);
    }
    arguments[arg_index] = NULL; // Null-terminate the array of arguments.
}

int main() {
    char command_line[MAX_COMMAND_LINE_LEN];
    char* arguments[MAX_COMMAND_LINE_ARGS];

    while (true) {
        // Print the shell prompt with the current working directory.
        char cwd[MAX_COMMAND_LINE_LEN];
        getcwd(cwd, sizeof(cwd));
        printf("%s> ", cwd);
        fflush(stdout);

        // Read input from stdin.
        if (!fgets(command_line, MAX_COMMAND_LINE_LEN, stdin)) {
            break;
        }

        // Check for empty command.
        if (strcmp(command_line, "\n") == 0) {
            continue;
        }

        // Tokenize the command line input.
        tokenize(command_line, arguments);

        // Implement Built-In Commands
        if (strcmp(arguments[0], "cd") == 0) {
            chdir(arguments[1]);
        } else if (strcmp(arguments[0], "pwd") == 0) {
            printf("%s\n", cwd);
        } else if (strcmp(arguments[0], "echo") == 0) {
            for (int i = 1; arguments[i]; i++) {
                printf("%s ", arguments[i]);
            }
            printf("\n");
        } else if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(arguments[0], "env") == 0) {
            for (int i = 0; environ[i]; i++) {
                printf("%s\n", environ[i]);
            }
        } else if (strcmp(arguments[0], "setenv") == 0) {
            if (arguments[1] && arguments[2]) {
                setenv(arguments[1], arguments[2], 1);
            } else {
                printf("setenv: Incorrect number of arguments.\n");
            }
        } else {
            // If not a built-in command, fork and execute.
            pid_t pid = fork();
            if (pid == 0) { // Child process.
                execvp(arguments[0], arguments);
                perror("execvp");  // If execvp returns, there was an error.
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork");
            } else {
                // Parent process waits for the child to complete.
                wait(NULL);
            }
        }
    }
    return 0;
}#define _POSIX_C_SOURCE 200112L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128
extern char **environ;

const char delimiters[] = " \n\t";

void tokenize(char* command_line, char** arguments) {
    int arg_index = 0;
    char* token = strtok(command_line, delimiters);
    while (token != NULL) {
        if (token[0] == '$') { // If the token starts with $, treat as environment variable.
            token = getenv(token + 1);
        }
        arguments[arg_index++] = token;
        token = strtok(NULL, delimiters);
    }
    arguments[arg_index] = NULL; // Null-terminate the array of arguments.
}

int main() {
    char command_line[MAX_COMMAND_LINE_LEN];
    char* arguments[MAX_COMMAND_LINE_ARGS];

    while (true) {
        // Print the shell prompt with the current working directory.
        char cwd[MAX_COMMAND_LINE_LEN];
        getcwd(cwd, sizeof(cwd));
        printf("%s> ", cwd);
        fflush(stdout);

        // Read input from stdin.
        if (!fgets(command_line, MAX_COMMAND_LINE_LEN, stdin)) {
            break;
        }

        // Check for empty command.
        if (strcmp(command_line, "\n") == 0) {
            continue;
        }

        // Tokenize the command line input.
        tokenize(command_line, arguments);

        // Implement Built-In Commands
        if (strcmp(arguments[0], "cd") == 0) {
            chdir(arguments[1]);
        } else if (strcmp(arguments[0], "pwd") == 0) {
            printf("%s\n", cwd);
        } else if (strcmp(arguments[0], "echo") == 0) {
            for (int i = 1; arguments[i]; i++) {
                printf("%s ", arguments[i]);
            }
            printf("\n");
        } else if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(arguments[0], "env") == 0) {
            for (int i = 0; environ[i]; i++) {
                printf("%s\n", environ[i]);
            }
        } else if (strcmp(arguments[0], "setenv") == 0) {
            if (arguments[1] && arguments[2]) {
                setenv(arguments[1], arguments[2], 1);
            } else {
                printf("setenv: Incorrect number of arguments.\n");
            }
        } else {
            // If not a built-in command, fork and execute.
            pid_t pid = fork();
            if (pid == 0) { // Child process.
                execvp(arguments[0], arguments);
                perror("execvp");  // If execvp returns, there was an error.
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork");
            } else {
                // Parent process waits for the child to complete.
                wait(NULL);
            }
        }
    }
    return 0;
}