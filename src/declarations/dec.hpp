#ifndef DEC_HPP
#define DEC_HPP

// Cvar Limits
#define MAX_CVARS 128
#define MAX_CVAR_NAME 32
#define MAX_CVAR_VALUE 64

// Weapon Limits
#define MAX_WEAPONS 10

// Cvar Struct
typedef struct Cvar {
    char name[MAX_CVAR_NAME];
    char value[MAX_CVAR_VALUE];
} Cvar;

// Weapon Struct
typedef struct Weapon {
    char name[32];
    int damage;
    int ammo;
} Weapon;

#endif
