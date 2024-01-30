#include "main.h"

/**
 * digits_count - A function to count how many digits a number has
 *
 * @n: The number whose digits we want to count
 * Return: How many digits the number has
 */

int digits_count(int n)
{
	int digs = 0;

	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		digs++;
	}
	return (digs);
}

/**
 * int_to_str - A function that converts an integer to strings of chars
 *
 * @n: The integer we want to convert
 * Return: A null terminated string of the digits of the n
 */

char *int_to_str(int n)
{
	char *str = NULL;
	int digs, divisor = 1;
	int i;

	digs = digits_count(n);

	for (i = 0; i < digs - 1; i++)
		divisor *= 10;

	str = malloc(sizeof(char) * digs + 1);
	if (str == NULL)
		return (NULL);
	for (i = 0; i < digs; i++)
	{
		str[i] = (n / divisor) + '0';
		n = n % divisor;
		divisor = divisor / 10;
	}
	str[i] = '\0';
	return (str);
}

void handle_decimal(char **buffer, char *spec, va_list val)
{
	int arg = va_arg(val, int);
	char *str_arg = int_to_str(arg);

	append_string(buffer, str_arg);
	free(str_arg);
	free(spec);
}
