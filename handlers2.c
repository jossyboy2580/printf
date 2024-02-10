#include "main.h"

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

/**
 * handle_oct - Handle all octadecimal conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_oct(char **buffer, char *spec, va_list val)
{
	unsigned int arg = va_arg(val, unsigned int);
	char *oct = oct_conv(arg);
	append_string(buffer, oct);
	free(oct);
	free(spec);
}

/**
 * handle_hex - Handle all hexadecimal conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_hex(char **buffer, char *spec, va_list val)
{
	unsigned int arg = va_arg(val, unsigned int);
	char *hex = hex_conv(arg, 0);
	append_string(buffer, hex);
	free(hex);
	free(spec);
}

/**
 * handle_pointer - Handle all hexadecimal conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_pointer(char **buffer, char *spec, va_list val)
{
	char *hex_prefill = "0x";
	void *arg = va_arg(val, void *);
	char *hex;
	
	if (arg == NULL)
	{
		arg = "(nil)";
		append_string(buffer, arg);
		free(spec);
		return;
	}
	hex = hex_conv_p((unsigned long)arg, 0);
	append_string(buffer, hex_prefill);
	append_string(buffer, hex);
	free(hex);
	free(spec);
}

/**
 * handle_bighex - Handle all hexadecimal conversions
 *
 * @buffer: The destination for storing the chars
 * @spec: The specifications to use
 * @val: Variadic functions list macro
 */
void handle_bighex(char **buffer, char *spec, va_list val)
{
	unsigned int arg = va_arg(val, unsigned int);
	char *hex = hex_conv(arg, 1);
	append_string(buffer, hex);
	free(hex);
	free(spec);
}
