#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * Executes the command "cat scores | grep <argument> | sort". 
 * This implementation adds the functionality to take one argument 
 * from the command line for the grep program and chains a sort 
 * process to the output of grep.
 *
 */

int main(int argc, char **argv)
{
    int pipefd1[2], pipefd2[2];
    int pid1, pid2;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <grep_arg>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *cat_args[] = {"cat", "scores", NULL};
    char *grep_args[] = {"grep", argv[1], NULL};
    char *sort_args[] = {"sort", NULL};

    // make two pipes (fds go in pipefd1 and pipefd2)
    pipe(pipefd1);
    pipe(pipefd2);

    pid1 = fork();

    if (pid1 == 0)
    {
        // First child (P2)
        pid2 = fork();

        if (pid2 == 0)
        {
            // Second child (P3) - sort
            // Replace standard input with input part of second pipe
            dup2(pipefd2[0], STDIN_FILENO);

            // Close unused ends of pipes
            close(pipefd1[0]);
            close(pipefd1[1]);
            close(pipefd2[1]);

            // Execute sort
            execvp("sort", sort_args);
            perror("execvp sort");
            exit(EXIT_FAILURE);
        }
        else
        {
            // First child (P2) - grep
            // Replace standard input with input part of first pipe
            dup2(pipefd1[0], STDIN_FILENO);

            // Replace standard output with output part of second pipe
            dup2(pipefd2[1], STDOUT_FILENO);

            // Close unused ends of pipes
            close(pipefd1[1]);
            close(pipefd2[0]);

            // Execute grep
            execvp("grep", grep_args);
            perror("execvp grep");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent (P1) - cat scores
        // Replace standard output with output part of first pipe
        dup2(pipefd1[1], STDOUT_FILENO);

        // Close unused ends of pipes
        close(pipefd1[0]);
        close(pipefd2[0]);
        close(pipefd2[1]);

        // Execute cat
        execvp("cat", cat_args);
        perror("execvp cat");
        exit(EXIT_FAILURE);
    }

    // The parent process should ideally wait for the child processes to exit
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}