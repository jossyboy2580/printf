#include "main.h"

void handle_string(char **buffer, char *spec, va_list val)
{
	char *str;

	str = va_arg(val, char *);
	append_string(buffer, str);
}

void handle_percent(char **buffer, char *spec, va_list val)
{
	append_char(buffer, '%');
}

void handle_char(char **buffer, char *spec, va_list val)
{
	char c;

	c = va_arg(val, int);
	printf("char is %c\n", c);
	append_char(buffer, c);
}
