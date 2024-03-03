#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

#define MAX_FILE_CONTENT_LENGTH 1000

void read_command(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    // Read the contents of the file
    char file_content[MAX_FILE_CONTENT_LENGTH];
    size_t bytes_read = fread(file_content, 1, MAX_FILE_CONTENT_LENGTH, file);

    // Null-terminate the string
    file_content[bytes_read] = '\0';

    // Print the contents of the file
    printf("%s\n", file_content);

    // Close the file
    fclose(file);
}
