#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// Function prototypes
void execute_command(const char *command);

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("CDo> ");
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Exit the shell if the user inputs "exit"
        if (strcmp(command, "exit") == 0)
            break;

        execute_command(command);
    }

    return 0;
}

void execute_command(const char *command) {
    // Check if the command starts with "echo"
    if (strncmp(command, "echo ", 5) == 0) {
        // If so, echo back the text after "echo"
        printf("%s\n", command + 5); // Print starting from the 6th character (after "echo ")
    } else {
        // Otherwise, just echo back the command
        printf("Executing command: %s\n", command);
    }
}
