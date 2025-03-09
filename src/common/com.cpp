#include "com.hpp"
#include <stdio.h>
#include <stdarg.h>

#include "../cvar/cvar.hpp"
#include "../color/codes.hpp"

void Com_Printf(const char *fmt, ...)
{
    va_list args;
    char buffer[1024]; 

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    printf("%s", buffer);
}

void Com_Dprintf(const char *fmt, ...)
{
   if (Cvar_FindVar("sven_dev") != NULL)
   {
    va_list args;
    char buffer[1024]; 

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    printf("%s", buffer);
   }
}


void Com_DCprintf(const char *fmt, ...) {
    if (Cvar_FindVar("sven_dev") != NULL) {
        va_list args;
        char buffer[1024]; 

        va_start(args, fmt);
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        va_end(args);

        // Call printColoredText directly
        printColoredText(buffer);
    }
}