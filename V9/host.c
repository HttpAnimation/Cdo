#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define MAX_OUTPUT_LENGTH 1000

void host_command(const char *command) {
    char output[MAX_OUTPUT_LENGTH];

    // Execute the specified command and capture its output
    FILE *cmd_output = popen(command, "r");
    if (cmd_output == NULL) {
        printf("Error: Failed to execute command\n");
        return;
    }

    // Read the output of the command
    while (fgets(output, sizeof(output), cmd_output) != NULL) {
        printf("%s", output);
    }

    // Close the command output stream
    pclose(cmd_output);
}
