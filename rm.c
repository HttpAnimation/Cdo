#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "commands.h"

void rm_command(const char *path) {
    int status;

    // Check if the path indicates removal of a folder
    if (strncmp(path, "-folder", 7) == 0) {
        // Remove the directory and its contents recursively
        status = system("rm -rf folder");
    } else {
        // Remove the file
        status = remove(path);
    }

    // Check if removal was successful
    if (status == 0) {
        printf("Removed: %s\n", path);
    } else {
        printf("Error: Failed to remove %s\n", path);
    }
}
