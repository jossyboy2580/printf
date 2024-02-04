#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

void handle_decimal(char **buffer, char *spec, va_list val);
void handle_pointer(char **buffer, char *spec, va_list val);
void handle_uint(char **buffer, char *spec, va_list val);
void handle_string(char **buffer, char *spec, va_list val);
void handle_bigstring(char **buffer, char *spec, va_list val);
void handle_percent(char **buffer, char *spec, va_list val);
void handle_char(char **buffer, char *spec, va_list val);
void handle_binary(char **buffer, char *spec, va_list val);
void handle_oct(char **buffer, char *spec, va_list val);
void handle_hex(char **buffer, char *spec, va_list val);
void handle_bighex(char **buffer, char *spec, va_list val);

char *filter_non_printable(char *str);

char *rot13(char *str);
void rev_string(char *str);
char *bin_conv(unsigned int num);
char *oct_conv(unsigned int num);
char *hex_conv(unsigned int num, int upper);
char *int_to_str(int arg);
char *uint_to_str(unsigned int arg);
void append_string(char **str, char *str2);
void append_char(char **str, char c);

#endif
