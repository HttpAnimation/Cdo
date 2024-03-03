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
    // Here, you can extend this function to handle various commands
    // For simplicity, let's just echo back the command
    printf("Executing command: %s\n", command);
}
