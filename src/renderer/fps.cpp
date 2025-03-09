#include "fps.hpp"
#include "../cvar/cvar.hpp"
#include <cstdlib>

int getFPS()
{
    Cvar* cvar = Cvar_FindVar("g_maxfps");

    if(!cvar)
    {
        Cvar_Set("g_maxfps", "60");
    }

    return 1000.0 / std::atof(cvar->value);
}