#include "main.h"
#include <string.h>


/**
 * assign_formatter - This function calls the appropraite formatter function
 *
 * @buffer: The buffer to store the processed string
 * @spec: The specification options
 * @specifier: The specifier to use
 * @val: A macro for the variadic functions
 */


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
		case 'b':
			handle_binary(buffer, spec, val);
			break;
		case 'p':
			break;
		case 'X':
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
			break;
		case '%':
			handle_percent(buffer, spec, val);
			break;
		default:
			break;
	}
}

/**
 * process_specifier - A function that decomposes the specifier options to use
 *
 * @fmt: The string we are parsing for the options
 * @pos: The index of the current character being looked at
 * @buff: Where we will store the result
 * @val: Variadic function macro
 */

void process_specifier(const char **fmt, int *pos, char **buff, va_list val)
{
	char *specifications = "cpdbiosSuxX%";
	char *spec = NULL;
	int starting_point = *pos;
	int spec_found = 0;
	char specifier;
	int entered = 1;
	int i;

	while ((*fmt)[*pos] != '\0')
	{
		spec = realloc(spec, sizeof(char) * (++entered));
		if (!spec)
			return;
		spec[entered - 2] = (*fmt)[*pos];
		for (i = 0; specifications[i] != '\0'; i++)
		{
			if ((*fmt)[*pos] == specifications[i])
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
	if (!spec_found)
	{
		append_string(buff, (char *)(*fmt + starting_point - 1));
		return;
	}
	spec[entered - 1] = '\0';
	assign_formatter(buff, spec, specifier, val);
}

/**
 * _printf - The custom printf being designed
 *
 * @format: The string of chars that contains the formating options
 *
 * Return: A count of how many chars were printed
 */

int _printf(const char *fmt, ...)
{
	char *buffer = NULL;
	va_list val;
	int count;
	int pos = 0;
		
	va_start(val, fmt);
	while (fmt[pos] != '\0')
	{
		if (fmt[pos] == '%')
		{
			pos++;
			process_specifier(&fmt, &pos, &buffer, val);
		}
		else
			append_char(&buffer, fmt[pos]);
		pos++;
	}
	va_end(val);
	count = write(1, buffer, strlen(buffer));
	free(buffer);
	return (count);
}
