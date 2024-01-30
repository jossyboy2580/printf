#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void handle_decimal(char **buffer, char *spec, va_list val);
int _printf(const char *format, ...);
void append_string(char **str, char *str2);
void append_char(char **str, char c);

#endif
