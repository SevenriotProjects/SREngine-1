#include "cl_commands.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "../cvar/cvar.hpp"
#include "../cmd/cmd.hpp"

void G_Maxfps()
{
    if(Cmd_Argc() != 2)
    {
        printf("Usage: g_maxfps <value>");
    } else {
        const char* value = Cmd_Argv(1);
        Cvar_Set("g_maxfps", value);
    }
}