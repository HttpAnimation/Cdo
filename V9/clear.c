#include <stdlib.h>
#include "commands.h"

#ifdef _WIN32
    #define CLEAR_SCREEN_COMMAND "cls"
#else
    #define CLEAR_SCREEN_COMMAND "clear"
#endif

void clear_command() {
    // Clear the screen using system-specific command
    system(CLEAR_SCREEN_COMMAND);
}
