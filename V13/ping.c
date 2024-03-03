#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ping_command(const char *url) {
    // Check if URL is provided
    if (url == NULL || url[0] == '\0') {
        printf("Error: Please provide a URL to ping.\n");
        return;
    }

    // Parse the hostname from the URL
    char hostname[256];
    if (sscanf(url, "https://%255[^/]", hostname) != 1) {
        printf("Error: Invalid URL format.\n");
        return;
    }

    // Execute ping command and read the output
    printf("Pinging %s...\n", hostname);
    char command[256];
    snprintf(command, sizeof(command), "ping -c 4 %s", hostname);
    system(command);
}
