#include <stdio.h>
#include <dirent.h>
#include "commands.h"

void ls_command() {
    // Open the current directory
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(".")) == NULL) {
        perror("opendir");
        return;
    }

    // Iterate over the entries in the directory and print them
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);
}
