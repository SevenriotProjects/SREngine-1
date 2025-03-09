#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cvar.hpp"

static Cvar cvars[MAX_CVARS];
static int cvar_count = 0;

// Find a cvar by name
Cvar *Cvar_FindVar(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        printf("Cvar_FindVar: Invalid name provided.\n");
        return NULL;
    }

    for (int i = 0; i < cvar_count; i++) {
        if (strcmp(cvars[i].name, name) == 0) {
            return &cvars[i];
        }
    }

    printf("Cvar_FindVar: Cvar '%s' not found.\n", name);
    return NULL;
}

// Set or add a cvar
void Cvar_Set(const char *name, const char *value) {
    if (name == NULL || value == NULL) {
        printf("Cvar_Set: Invalid arguments.\n");
        return;
    }

    if (strlen(name) >= MAX_CVAR_NAME || strlen(value) >= MAX_CVAR_VALUE) {
        printf("Cvar_Set: Name or value exceeds allowed size.\n");
        return;
    }

    for (int i = 0; i < cvar_count; i++) {
        if (strcmp(cvars[i].name, name) == 0) {
            strncpy(cvars[i].value, value, MAX_CVAR_VALUE - 1);
            cvars[i].value[MAX_CVAR_VALUE - 1] = '\0';
            return;
        }
    }

    if (cvar_count >= MAX_CVARS) {
        printf("Cvar_Set: Cvar limit reached (%d).\n", MAX_CVARS);
        return;
    }

    strncpy(cvars[cvar_count].name, name, MAX_CVAR_NAME - 1);
    cvars[cvar_count].name[MAX_CVAR_NAME - 1] = '\0';

    strncpy(cvars[cvar_count].value, value, MAX_CVAR_VALUE - 1);
    cvars[cvar_count].value[MAX_CVAR_VALUE - 1] = '\0';

    cvar_count++;
}

// Get the value of a cvar by name
const char *Cvar_Get(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        printf("Cvar_Get: Invalid name provided.\n");
        return NULL;
    }

    for (int i = 0; i < cvar_count; i++) {
        if (strcmp(cvars[i].name, name) == 0) {
            return cvars[i].value;
        }
    }

    printf("Cvar_Get: Cvar '%s' not found.\n", name);
    return NULL;
}
