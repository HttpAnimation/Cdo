#ifndef COMMANDS_H
#define COMMANDS_H

// Function prototypes for command implementations
void echo_command(const char *argument);
void read_command(const char *argument);
void ls_command();
void clear_command();
void exit_command();
void host_command(const char *command);

#endif /* COMMANDS_H */
