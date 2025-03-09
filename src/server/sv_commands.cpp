#include "sv_commands.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "../cmd/cmd.hpp"

void test()
{
    printf("hi\n");
}

/*void set(const char* name, const char* value)
{
    Cvar_Set(name, value);
    Com_Printf("%s successfully set to %s\n", name, value);
}old*/

void getcvar()
{
    if (Cmd_Argc() < 2)
    {
        printf("Usage: getcvar <name>\n");
        return;
    }

    const char* name = Cmd_Argv(1);

    Cvar* cvar = Cvar_FindVar(name);
    if (cvar != nullptr)
    {
        printf("%s is %s\n", name, cvar->value);
    }
    else
    {
        printf("Cvar '%s' not found\n", name);
    }
}


 // for future xd
void set() {
    if (Cmd_Argc() < 3) {
        printf("Usage: set <name> <value>\n");
        return;
    }
    const char* name = Cmd_Argv(1);
    const char* value = Cmd_Argv(2);
    printf("Setting %s to %s\n", name, value);
    Cvar_Set(name, value);
}

void clear()
{
    system("cls");
}