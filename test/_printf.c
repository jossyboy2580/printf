#include "main.h"

void assign_formatter(char **buffer, char *spec, char specifier, va_list val)
{
	switch (specifier)
	{
		case 'd':
			handle_decimal(buffer, spec, val);
			break;
		case 'c':
			break;
		case 'e':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'i':
			break;
		case 'o':
			break;
		case 's':
			break;
		case 'u':
			break;
		case 'x':
		case '%':
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

	while ((*format)[*pos] != '\0' && (spec_found == 0))
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
		(*pos)++;
	}
	spec[entered - 1] = '\0';
	printf("%s", spec);
	assign_formatter(buffer, spec, specifier, val);
}

void _printf(const char *format, ...)
{
	char *buffer = NULL;
	int formatter_seen = 0;
	int escapper_seen = 0;
	va_list val;
	char c;
	int pos = 0, number, n_digits, i;

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
	for (i = 0; buffer[i] != '\0'; i++)
	{
		putchar(buffer[i]);
	}
}

int main(void)
{
	_printf("one is: %dand two is: %d\n", 1, 334);
	return (0);
}
