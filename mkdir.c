#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

void mkdir_command(const char *directory_name) {
    // Create the directory using system command mkdir
    int status = mkdir(directory_name, 0777); // 0777 gives read, write, and execute permissions to everyone
    if (status == 0) {
        printf("Directory '%s' created successfully.\n", directory_name);
    } else {
        printf("Error: Failed to create directory '%s'\n", directory_name);
    }
}
