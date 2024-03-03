#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void start_command(const char *script) {
    // Check if script is provided
    if (script == NULL || script[0] == '\0') {
        printf("Error: Please provide a script to start.\n");
        return;
    }

    // Open the script file for reading
    FILE *file = fopen(script, "r");
    if (file == NULL) {
        printf("Error: Failed to open script '%s'\n", script);
        return;
    }

    // Read and execute each line of the script
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Parse the command and arguments
        char *token = strtok(line, " ");
        char *args = strtok(NULL, "");

        // Execute the command
        if (token != NULL) {
            if (strcmp(token, "exit") == 0) {
                exit_command();
                break;
            } else if (strcmp(token, "echo") == 0) {
                echo_command(args);
            } else if (strcmp(token, "read") == 0) {
                read_command(args);
            } else if (strcmp(token, "ls") == 0) {
                ls_command();
            } else if (strcmp(token, "clear") == 0) {
                clear_command();
            } else if (strcmp(token, "host") == 0) {
                host_command(args);
            } else if (strcmp(token, "help") == 0) {
                help_command();
            } else if (strcmp(token, "mkdir") == 0) {
                mkdir_command(args);
            } else if (strcmp(token, "rm") == 0) {
                char *flag = strtok(args, " ");
                char *path = strtok(NULL, "");
                rm_command(flag, path);
            } else if (strcmp(token, "ping") == 0) {
                ping_command(args);
            } else if (strcmp(token, "v") == 0) {
                v_command();
            } else if (strcmp(token, "start") == 0) {
                start_command(args); // Recursive call to handle nested scripts
            } else {
                printf("Unknown command: %s\n", token);
            }
        }
    }

    // Close the script file
    fclose(file);
}
