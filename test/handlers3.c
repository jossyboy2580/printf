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
	unsigned int arg = va_arg(val, int);
	char *str_arg = uint_to_str(arg);

	append_string(buffer, str_arg);
	free(str_arg);
	free(spec);
}
