#include "main.h"

/**
 * rot13 - A function to implement the rot13 substitution cipher
 *
 * @s: The string we want to map
 * Return: the pointer to the string s
 */
char *rot13(char *s)
{
	char *domain = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *co_domain = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; domain[j]; j++)
		{
			if (s[i] == domain[j])
			{
				s[i] = co_domain[j];
				break;
			}
		}
	}
	return (s);
}

/**
 * get_width - A function to get the width of a format specifier
 *
 * @spec: The specifier string we're scanning for the string
 * Return: A width for the string
 */

int get_width(char *spec)
{
	unsigned int i;

	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] >= '1' && spec[i] <= '9')
		{
			if (spec[i + 1] == '.' || spec[i + 2] == '\0')
				return (spec[i] - '0');
		}
		i++;
	}
	return (-1);
}

/**
 * get_precision - A function to get the precision of a format specifier
 *
 * @spec: The specifier string we're scanning for the string
 * Return: A width for the string
 */

int get_precision(char *spec)
{
	unsigned int i;

	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] >= '0' && spec[i] <= '9')
		{
			if (spec[i - 1] == '.' || spec[i + 2] == '\0')
				return (spec[i] - '0');
		}
		i++;
	}
	return (-1);
}
