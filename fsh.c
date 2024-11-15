#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char input[1024];  // Array to store user input
    char *args[100];   // Array to store command and arguments
    int i;

    while (1) {
        printf("fsh> ");  // Print the shell prompt

        // Read the input from the user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }

        // Remove newline character at the end of the input
        input[strcspn(input, "\n")] = 0;

        // If the input is "exit", exit the shell
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // If the input starts with "cd", handle it separately
        if (strncmp(input, "cd", 2) == 0) {
            // Extract the directory argument
            char *dir = input + 3;  // Skip "cd " part

            // Check if the directory argument is provided
            if (dir[0] == 0) {
                printf("cd: nope not here\n");
            } else {
                // Try to change the directory
                if (chdir(dir) != 0) {
                    perror("cd");
                }
            }
            continue;  // Skip the rest of the loop and prompt again
        }

        // Split the input into arguments
        i = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // Null-terminate the argument array

        // Fork!!
        pid_t pid = fork();

        if (pid == 0) {  // Child process
            // Execute the command using execvp
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);  // Exit if exec fails
            }
        } else if (pid > 0) {  // Parent process
            wait(NULL);  // Wait for the child process to finish
        } else {
            perror("fork");
            exit(1);
        }
    }

    printf("Bye! Leaving the shell...\n");
    return 0;
}

