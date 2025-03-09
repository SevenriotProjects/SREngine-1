#include <stdio.h>
#include <stdarg.h>
#include "console.hpp"

FILE *log_file;

int console_init() {
    log_file = fopen("engine.log", "w");
    if (!log_file) {
        perror("Error opening log file");
        return 0;
    }
    return 1;
}

void console_log(const char *level, const char *format, ...) {
    if (!log_file) return;

    va_list args;
    va_start(args, format);
    fprintf(log_file, "[%s] ", level);
    vfprintf(log_file, format, args);
    fprintf(log_file, "\n");
    fflush(log_file);
    va_end(args);
}

void console_cleanup() {
    if (log_file) fclose(log_file);
}
