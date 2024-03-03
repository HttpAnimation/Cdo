#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR_SCREEN_COMMAND "cls"
#else
    #define CLEAR_SCREEN_COMMAND "clear"
#endif

#define MAX_COMMAND_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

// Function prototypes
void execute_command(const char *command);

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("CDo> ");
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Exit the shell if the user inputs "exit"
        if (strcmp(command, "exit") == 0)
            break;

        execute_command(command);
    }

    return 0;
}

void execute_command(const char *command) {
    // Check if the command starts with "echo"
    if (strncmp(command, "echo ", 5) == 0) {
        // If so, echo back the text after "echo"
        printf("%s\n", command + 5); // Print starting from the 6th character (after "echo ")
    } 
    // Check if the command starts with "read"
    else if (strncmp(command, "read ", 5) == 0) {
        // Get the filename
        const char *filename = command + 5;

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
    // Check if the command is "ls"
    else if (strcmp(command, "ls") == 0) {
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
    // Check if the command is "clear"
    else if (strcmp(command, "clear") == 0) {
        // Clear the screen using system-specific command
        system(CLEAR_SCREEN_COMMAND);
    }
    else {
        // Otherwise, just echo back the command
        printf("Executing command: %s\n", command);
    }
}
