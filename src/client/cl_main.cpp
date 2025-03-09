#include "cl.hpp"
#include <ctime>
#include <stdio.h>
#include "..\console\console.hpp"
#include "cl_commands.hpp"
#include "../cmd/cmd.hpp"

void CL_AddCommands()
{
    Cmd_AddCommand("g_maxfps", G_Maxfps);

}

void CL_Shutdown()
{
    time_t timestamp;
    time(&timestamp);
    printf("%s", "-- Client Shutdown --");
//    sdl_cleanup();
    console_log("-- CLIENT SHUTDOWN -- DATE -- ", ctime(&timestamp));
}
