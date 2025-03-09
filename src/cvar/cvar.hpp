#ifndef CVAR_H
#define CVAR_H
#include "..\declarations\dec.hpp"

Cvar *Cvar_FindVar(const char *name);
void Cvar_Set(const char *name, const char *value);
const char *Cvar_Get(const char *name);

#endif
