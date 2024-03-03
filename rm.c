#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "commands.h"

void rm_command(const char *flag, const char *path) {
    int status;

    // Check if the flag is "-folder"
    if (strcmp(flag, "-folder") == 0) {
        // Check if the path is a directory
        struct stat st;
        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            // Remove the directory and its contents recursively
            char command[1024];
            snprintf(command, sizeof(command), "rm -rf %s", path);
            status = system(command);
        } else {
            printf("Error: %s is not a directory.\n", path);
            return;
        }
    } else {
        printf("Error: Specify -folder to remove a directory.\n");
        return;
    }

    // Check if removal was successful
    if (status == 0) {
        printf("Removed: %s\n", path);
    } else {
        printf("Error: Failed to remove %s\n", path);
    }
}
