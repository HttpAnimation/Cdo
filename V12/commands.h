#ifndef COMMANDS_H
#define COMMANDS_H

// Function prototypes for command implementations
void echo_command(const char *argument);
void read_command(const char *argument);
void ls_command();
void clear_command();
void exit_command();
void host_command(const char *command);
void help_command();
void mkdir_command(const char *directory_name);
void rm_command(const char *flag, const char *path); // Update rm command prototype
void ping_command(const char *url); // Add ping command prototype
void v_command(); // Add v command prototype
void start_command(const char *script); // Add start command prototype

// Add declaration for execute_command
void execute_command(const char *command);

#endif /* COMMANDS_H */