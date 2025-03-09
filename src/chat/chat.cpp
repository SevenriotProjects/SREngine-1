#include <stdio.h>
#include <string.h>
#include "chat.hpp"

#define MAX_CHAT_MESSAGES 100000 // maybe crash?

typedef struct {
    char sender[32];
    char message[256];
} ChatMessage; // stfu

static ChatMessage messages[MAX_CHAT_MESSAGES];
static int message_count = 0;

void chat_send(const char *sender, const char *message) {
    if (message_count >= MAX_CHAT_MESSAGES) {
        printf("Chat message limit reached.\n");
        return;
    }

    strncpy(messages[message_count].sender, sender, 32);
    strncpy(messages[message_count].message, message, 256);
    message_count++;
}

void chat_print_all() {
    for (int i = 0; i < message_count; i++) {
        printf("[%s]: %s\n", messages[i].sender, messages[i].message);
    }
}
