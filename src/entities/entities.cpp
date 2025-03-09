#include <stdio.h>
#include <string.h>
#include "entities.hpp"

typedef struct {
    char name[32];
    float x, y;
} Entity;

static Entity entities[MAX_ENTITIES];
static int entity_count = 0;

void entity_create(const char *name, float x, float y) {
    if (entity_count >= MAX_ENTITIES) {
        printf("Entity limit reached.\n");
        return;
    }

    strncpy(entities[entity_count].name, name, 32);
    entities[entity_count].x = x;
    entities[entity_count].y = y;
    entity_count++;
}

void entity_print_all() {
    for (int i = 0; i < entity_count; i++) {
        printf("Entity: %s at (%.2f, %.2f)\n", entities[i].name, entities[i].x, entities[i].y);
    }
}
