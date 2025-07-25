#include "cli.h"
#include "filesystem.h"
#include <string.h>

void print_prompt() {
    const char* prompt = "OS> ";
    // Code to print prompt to the screen (placeholder)
}

void read_command(char* buffer, size_t size) {
    // Code to read user input into buffer (placeholder)
}

void process_command(const char* command) {
    if (strncmp(command, "create ", 7) == 0) {
        // Code to create a file
        const char* data = "Sample data"; // Placeholder data
        create_file(command + 7, data);
    } else if (strncmp(command, "read ", 5) == 0) {
        // Code to read a file
        const char* data = read_file(command + 5);
        // Print data to screen (placeholder)
    }
}

void start_cli() {
    char command[256];
    while (true) {
        print_prompt();
        read_command(command, sizeof(command));
        process_command(command);
    }
}
