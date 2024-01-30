#include "main.h"
#include <string.h>

void assign_formatter(char **buffer, char *spec, char specifier, va_list val)
{
	switch (specifier)
	{
		case 'd':
			handle_decimal(buffer, spec, val);
			break;
		case 'c':
			handle_char(buffer, spec, val);
			break;
		case 'e':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'i':
			handle_decimal(buffer, spec, val);
			break;
		case 'o':
			break;
		case 's':
			handle_string(buffer, spec, val);
			break;
		case 'u':
			break;
		case 'x':
		case '%':
			handle_percent(buffer, spec, val);
			break;
		default :
			break;
	}
}

void process_specifier(const char **format, int *pos, char **buffer, va_list val)
{
	char *specifications = "cdefgiosux%";
	char *spec = NULL;
	int spec_found = 0;
	char specifier;
	int entered = 1;
	int i;

	while ((*format)[*pos] != '\0')
	{
		spec = realloc(spec, sizeof(char) * (++entered));
		if (!spec)
			return;
		spec[entered - 2] = (*format)[*pos];
		for (i = 0; specifications[i] != '\0'; i++)
		{
			if ((*format)[*pos] == specifications[i])
			{
				specifier = specifications[i];
				spec_found = 1;
				break;
			}
		}
		if (spec_found)
			break;
		(*pos)++;
	}
	spec[entered - 1] = '\0';
	assign_formatter(buffer, spec, specifier, val);
}

int _printf(const char *format, ...)
{
	char *buffer = NULL;
	va_list val;
	int count;
	int pos = 0;

	va_start(val, format);
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			process_specifier(&format, &pos, &buffer, val);
		}
		else
			append_char(&buffer, format[pos]);
		pos++;
	}
	va_end(val);
	count = write(1, buffer, strlen(buffer));
	free(buffer);
	return (count);
}
