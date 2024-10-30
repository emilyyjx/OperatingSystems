Design and Documentation Report
Objective:
The provided code serves as a basic shell implementation capable of executing certain built-in
commands as well as any other system command. It does so by tokenizing input, checking for
built-in commands, and using system calls to run external commands.
Design Choices:
1. POSIX Compliance:
- The code begins with `#define _POSIX_C_SOURCE 200112L` which ensures the program
uses the POSIX.1-2001 standard. This ensures compatibility and a consistent environment.
2. Command Limits:
- The program uses defined constants for command line length and the number of arguments
which provides a clear boundary for the system's capacity and aids in buffer management.
3. Tokenization:
- The `tokenize` function uses `strtok` to split the input command based on space, newline,
and tab delimiters. This modular design allows for easy modifications to the tokenization process
if needed in the future.
4. Environment Variables:
- The code acknowledges environment variables by checking if the token starts with a `$` sign.
It then fetches the corresponding environment variable value using the `getenv` function.
5. Built-In Commands:
- The built-in commands (`cd`, `pwd`, `echo`, `exit`, `env`, and `setenv`) are handled directly
in the `main` function. This design choice makes it simpler to expand or modify the list of
supported built-in commands in the future.
6. Fork and Execute Model:
- For non-built-in commands, the shell forks a new process and attempts to execute the
command using `execvp`. This is the traditional way Unix-based shells operate, allowing the
parent shell to continue functioning independently of the child processes.
7. Error Handling:
- Proper error handling is done using the `perror` function to display relevant error messages.
This aids in debugging and provides feedback to the user in case of issues.
Documentation of Code Sections:
1. Headers and Macros:
- Necessary headers are included for functions such as `fork`, `execvp`, and `strtok`.
- Defined constants set the boundaries for command input and arguments.
2. Tokenize Function:
- Splits the input command into tokens (arguments) using specified delimiters.
- Checks and translates environment variables starting with a `$` sign.
3. Main Function:
- Initiates an infinite loop to mimic a shell's persistent prompt.
- Prints the current working directory as the shell prompt.
- Fetches user input and checks for the newline (empty command).
- Calls the `tokenize` function to split the command.
- Handles built-in commands directly.
- For external commands, it forks and attempts to execute the command. If the command
execution fails, an error is displayed.
- Parent process waits for the child process to complete before continuing.
In conclusion, the design of this basic shell is clear and modular. Future enhancements can easily
be incorporated due to the structured approach. Proper error handling and feedback mechanisms
ensure that the user is informed about any issues during execution.
