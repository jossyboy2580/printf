#include "main.h"

/**
 * handle_uint - Handle all unsigned integer conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */

void handle_uint(char **buffer, char *spec, va_list val)
{
	unsigned long int arg = va_arg(val, unsigned long int);
	char *str_arg;

	str_arg = uint_to_str(arg);
	append_string(buffer, str_arg);
	free(str_arg);
	free(spec);
}

/**
 * handle_reverse - Reverse the argument
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */

void handle_reverse(char **buffer, char *spec, va_list val)
{
	char *str = strdup(va_arg(val, char *));

	if (str == NULL)
		str = "(nil)";
	rev_string(str);
	append_string(buffer, str);
	free(spec);
	free(str);
}

/**
 * handle_rot13 - Rotate the string argument
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_rot13(char **buffer, char *spec, va_list val)
{
	char *str = strdup(va_arg(val, char *));
	char *rotated;

	if (str == NULL)
		str = "(nil)";
	rotated = rot13(str);
	append_string(buffer, rotated);
	free(spec);
	free(str);
}
