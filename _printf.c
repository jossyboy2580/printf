#include "main.h"
#include <string.h>

void _print_recurser(char **buf, char *fmt, int *pos, va_list val);
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
			handle_pointer(buffer, spec, val);
			break;
		case 'X':
			handle_bighex(buffer, spec, val);
			break;
		case 'i':
			handle_decimal(buffer, spec, val);
			break;
		case 'o':
			handle_oct(buffer, spec, val);
			break;
		case 's':
			handle_string(buffer, spec, val);
			break;
		case 'S':
			handle_bigstring(buffer, spec, val);
			break;
		case 'u':
			handle_uint(buffer, spec, val);
			break;
		case 'r':
			handle_reverse(buffer, spec, val);
			break;
		case 'R':
			handle_rot13(buffer, spec, val);
			break;
		case 'x':
			handle_hex(buffer, spec, val);
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

void process_specifier(char *fmt, int *pos, char **buff, va_list val)
{
	char *specifications = "cpirRdbiosSuxX%";
	char *spec = NULL;
	int current_pos = *pos;
	int spec_found = 0;
	char specifier;
	int entered = 1;
	int i;

	while (fmt[*pos] != '\0')
	{
		spec = realloc(spec, sizeof(char) * (++entered));
		if (!spec)
			return;
		spec[entered - 2] = fmt[*pos];
		for (i = 0; specifications[i] != '\0'; i++)
		{
			if (fmt[*pos] == specifications[i])
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
	if (current_pos != *pos)
		spec[entered - 1] = '\0';
	if (!spec_found)
	{
		append_char(buff, '%');
		free(spec);
		(*pos) = current_pos;
		_print_recurser(buff, fmt, pos, val);
		return;
	}
	else
		assign_formatter(buff, spec, specifier, val);
}

/**
 * _print_recurser - A function that decomposes the specifier options to use
 *
 * @fmt: The string we are parsing for the options
 * @pos: The index of the current character being looked at
 * @buff: Where we will store the result
 * @val: Variadic function macro
 */

void _print_recurser(char **buff, char *fmt, int *pos, va_list val)
{
	while (fmt[*pos] != '\0')
	{
		if (fmt[*pos] == '%')
		{
			(*pos)++;
			process_specifier(fmt, pos, buff, val);
		}
		else
			append_char(buff, fmt[*pos]);
		(*pos)++;
	}
}

/**
 * _printf - The custom printf being designed
 *
 * @fmt: The string of chars that contains the formating options
 *
 * Return: A count of how many chars were printed
 */

int _printf(const char *fmt, ...)
{
	char *buffer = NULL;
	va_list val;
	int count;
	int pos = 0;

	if (fmt == NULL || strlen(fmt) == 0)
		return (0);
	va_start(val, fmt);
	_print_recurser(&buffer, (char *)fmt, &pos, val);
	va_end(val);
	count = write(1, buffer, strlen(buffer));
	free(buffer);
	return (count);
}
