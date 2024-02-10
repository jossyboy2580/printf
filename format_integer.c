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
 * udigits_count - A function to count how many digits a number has
 *
 * @n: The number whose digits we want to count
 * Return: How many digits the number has
 */

unsigned int udigits_count(unsigned long int n)
{
	unsigned int digs = 0;

	if (n == 0)
		return (1);
	while (n)
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
	int dig;
	int digs, divisor = 1;
	int i = 0;
	int negative = 0;

	if (n < 0)
	{
		negative = 1;
		if (n == -1)
		{
			negative = 0;
			n = -n;
		}
		else
			n = -1 * (n + 1);
	}
	digs = digits_count(n);

	for (i = 0; i < digs - 1; i++)
		divisor *= 10;

	i = 0;
	str = malloc(sizeof(char) * digs + negative + 1);
	if (str == NULL)
		return (NULL);
	if (negative)
	{
		str[i++] = '-';
	}
	for (i = i; i < digs + negative; i++)
	{
		dig = n / divisor;
		if (i == digs + negative - 1 && negative)
			dig++;
		str[i] = dig + '0';
		n = n % divisor;
		divisor = divisor / 10;
	}
	str[i] = '\0';
	return (str);
}

/**
 * uint_to_str - A function that converts an integer to strings of chars
 *
 * @n: The integer we want to convert
 * Return: A null terminated string of the digits of the n
 */

char *uint_to_str(unsigned long int n)
{
	char *str = NULL;
	int dig;
	unsigned long int digs, divisor = 1;
	unsigned long int i = 0;

	digs = udigits_count(n);

	for (i = 0; i < digs - 1; i++)
		divisor *= 10;

	i = 0;
	str = malloc(sizeof(char) * digs + 1);
	if (str == NULL)
		return (NULL);
	for (i = i; i < digs; i++)
	{
		dig = n / divisor;
		str[i] = dig + '0';
		n = n % divisor;
		divisor = divisor / 10;
	}
	str[i] = '\0';
	return (str);
}
