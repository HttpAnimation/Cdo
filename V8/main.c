#include <stdio.h>
#include <string.h>
#include "commands.h"

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("CDo> ");
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Parse the command and argument (if any)
        char *token = strtok(command, " ");
        char *argument = strtok(NULL, " ");

        // Exit the shell if the user inputs "exit"
        if (strcmp(token, "exit") == 0) {
            exit_command();
            break;
        }

        // Execute the appropriate command based on the token
        if (strcmp(token, "echo") == 0) {
            echo_command(argument);
        } else if (strcmp(token, "read") == 0) {
            read_command(argument);
        } else if (strcmp(token, "ls") == 0) {
            ls_command();
        } else if (strcmp(token, "clear") == 0) {
            clear_command();
        } else if (strcmp(token, "host") == 0) {
            host_command(argument);
        } else if (strcmp(token, "help") == 0) {
            help_command();
        } else {
            printf("Unknown command: %s\n", token);
        }
    }

    return 0;
}
