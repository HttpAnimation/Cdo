#include <stdio.h>
#include <stdlib.h>
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

        // Exit the shell if the user inputs "exit"
        if (strcmp(token, "exit") == 0) {
            exit_command();
            break;
        }

        // Execute the appropriate command based on the token
        if (strcmp(token, "echo") == 0) {
            char *argument = strtok(NULL, "");
            echo_command(argument);
        } else if (strcmp(token, "read") == 0) {
            char *argument = strtok(NULL, "");
            read_command(argument);
        } else if (strcmp(token, "ls") == 0) {
            ls_command();
        } else if (strcmp(token, "clear") == 0) {
            clear_command();
        } else if (strcmp(token, "host") == 0) {
            char *argument = strtok(NULL, "");
            host_command(argument);
        } else if (strcmp(token, "help") == 0) {
            help_command();
        } else if (strcmp(token, "mkdir") == 0) {
            char *argument = strtok(NULL, "");
            mkdir_command(argument);
        } else if (strcmp(token, "rm") == 0) {
            char *flag = strtok(NULL, " ");
            char *path = strtok(NULL, "");
            rm_command(flag, path);
        } else if (strcmp(token, "ping") == 0) {
            char *url = strtok(NULL, "");
            ping_command(url);
        } else if (strcmp(token, "v") == 0) {
            v_command();
        } else if (strcmp(token, "start") == 0) {
            char *script = strtok(NULL, "");
            start_command(script);
        } else {
            printf("Unknown command: %s\n", token);
        }
    }

    return 0;
}
