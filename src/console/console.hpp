#ifndef CONSOLE_H
#define CONSOLE_H

int console_init();
void console_log(const char *level, const char *format, ...);
void console_cleanup();

#endif
