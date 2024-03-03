#include <stdio.h>

void v_command() {
    // Open the file for reading
    FILE *file = fopen("version.dni", "r");
    if (file == NULL) {
        printf("Error: Unable to open file 'version.dni'\n");
        return;
    }

    // Read and print the contents of the file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);
}
