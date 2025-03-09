#include "sv_main.hpp"
#include "sv_commands.hpp"
#include "../cmd/cmd.hpp"

void SV_AddOperatorCommand()
{
    Cmd_AddCommand("test", test);
    Cmd_AddCommand("getcvar", getcvar);
    Cmd_AddCommand("set", set);
    Cmd_AddCommand("clear", clear);
}