#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        // Execute the command
        system(line);
    }

    // Close the script file
    fclose(file);
}
