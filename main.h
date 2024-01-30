#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

void handle_decimal(char **buffer, char *spec, va_list val);
void handle_string(char **buffer, char *spec, va_list val);
void handle_percent(char **buffer, char *spec, va_list val);
void handle_char(char **buffer, char *spec, va_list val);

void append_string(char **str, char *str2);
void append_char(char **str, char c);

#endif