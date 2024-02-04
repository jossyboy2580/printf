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
