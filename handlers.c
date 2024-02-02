#include "main.h"

/**
 * handle_string - Handle all string conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */

void handle_string(char **buffer, char *spec, va_list val)
{
	char *str;

	(void)(spec);
	str = va_arg(val, char *);
	if (str == NULL)
		str = "(nil)";
	append_string(buffer, str);
}


/**
 * handle_percent - Handle all percent conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */

void handle_percent(char **buffer, char *spec, va_list val)
{
	(void)(val);
	(void)(spec);
	append_char(buffer, '%');
}


/**
 * handle_char - Handle all char conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */

void handle_char(char **buffer, char *spec, va_list val)
{
	char c;

	(void)(spec);
	c = va_arg(val, int);
	append_char(buffer, c);
}

/**
 * handle_decimal - Handle all decimal and integer conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_decimal(char **buffer, char *spec, va_list val)
{
	int arg = va_arg(val, int);
	char *str_arg = int_to_str(arg);

	append_string(buffer, str_arg);
	free(str_arg);
	free(spec);
}

/**
 * handle_binary - Handle all binary conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_binary(char **buffer, char *spec, va_list val)
{
	unsigned int arg = va_arg(val, unsigned int);
	char *bin = bin_conv(arg);
	append_string(buffer, bin);
	free(bin);
	free(spec);
}
