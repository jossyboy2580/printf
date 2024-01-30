#include "main.h"

/**
 * _printf - a funxn that returns the number of characters printed excluding null byte,
 * writes output to stdout
 * @format: format for the string
 * Return: an int value
 */

int _printf(const char *format, ...)
{
	int chars_printed = 0;

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				chars_printed++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				chars_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				chars_printed += str_len;
			}
		}
		format++;
	}
	va_end(args);

	return (chars_printed);
}

int main(void)
{
	_printf("man\n");
	_printf("%c\n", 'v');
	_printf("%s\n", "john");
	_printf("%%\n");

	return (0);
}
