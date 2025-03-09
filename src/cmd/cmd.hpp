#ifndef CMD_H
#define CMD_H

typedef void (*command_func_t)();

const char* Cmd_Argv(int index);
int Cmd_Argc();

void Cmd_AddCommand(const char *name, command_func_t func);
void Cmd_ExecuteCommand(const char *input);

#endif
