#include <stdio.h>
#include <stdlib.h>

void ping_command(const char *url) {
    // Check if URL is provided
    if (url == NULL || url[0] == '\0') {
        printf("Error: Please provide a URL to ping.\n");
        return;
    }

    // Execute ping command and read the output
    printf("Pinging %s...\n", url);
    char command[256];
    snprintf(command, sizeof(command), "ping -c 4 %s", url);
    system(command);
}
