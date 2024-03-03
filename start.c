#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start_command(const char *script) {
    // Check if script is provided
    if (script == NULL || script[0] == '\0') {
        printf("Error: Please provide a script to start.\n");
        return;
    }

    // Execute the Bash script
    int status = system(script);
    if (status != 0) {
        printf("Error: Failed to execute script '%s'\n", script);
    }
}
