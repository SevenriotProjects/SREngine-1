#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmd.hpp"

#define MAX_COMMANDS 128
#define MAX_ARGS 10

typedef struct {
    char name[32];
    command_func_t func;
} Command;

static Command commands[MAX_COMMANDS];
static int command_count = 0;

static int argc = 0;
static char* argv[MAX_ARGS];

int Cmd_Argc() {
    return argc;
}

const char* Cmd_Argv(int index) {
    if (index < 1 || index >= argc) {
        return "";
    }
    return argv[index];
}


void Cmd_AddCommand(const char *name, command_func_t func) {
    if (command_count >= MAX_COMMANDS) {
        printf("Command limit reached.\n");
        return;
    }

    strncpy(commands[command_count].name, name, 32);
    commands[command_count].func = func;
    command_count++;
}

/*void Cmd_ExecuteCommand(const char *input) { // [old one] filled with bugs
    for (int i = 0; i < command_count; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].func();
            return;
        }
    }
    printf("Unknown command: %s\n", input);
}*/

void Cmd_ExecuteCommand(const char *input) {
    // Parse input into argc and argv
    char buffer[256];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    argc = 0;
    char *token = strtok(buffer, " ");
    while (token && argc < MAX_ARGS) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    if (argc == 0) {
        printf("No command entered.\n");
        return;
    }

    // Compare only the first token (argv[0]) with the registered command names
    for (int i = 0; i < command_count; i++) {
        if (strcmp(argv[0], commands[i].name) == 0) {
            commands[i].func(); // Call the associated function
            return;
        }
    }

    printf("Unknown command: %s\n", argv[0]);
}
