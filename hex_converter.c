#include "main.h"

/**
 * hex_conv - A function to get the octadecimal value of a number
 *
 * @num: The number we want to compute for
 * Return: A string containing the octal value of num
 */

char *hex_conv(unsigned int num, int upper)
{
	char *hex = NULL;
	unsigned int len = 1;
	int overflow = upper == 1 ? 7 : 39;
	int rem;

	if (num == 0)
	{
		len = 2;
		hex = malloc(sizeof(char) * len);
		if (!hex)
		{
			printf("Malloc of hexadecimal number failed\n");
			return (NULL);
		}
		hex[len - 2] = 0 + '0';
	}
	while (num)
	{
		hex = realloc(hex, sizeof(char) * ++len);
		if (!hex)
			return (NULL);
		rem = num % 16;
		if (rem > 9)
		{
			rem = rem + overflow;
		}
		num = num / 16;
		hex[len - 2] = rem + '0';
	}
	hex[len - 1] = '\0';
	rev_string(hex);
	return (hex);
}

/**
 * hex_conv_p - A function to get the octadecimal value of a number
 *
 * @num: The number we want to compute for
 * Return: A string containing the octal value of num
 */

char *hex_conv_p(unsigned long num, int upper)
{
	char *hex = NULL;
	unsigned int len = 1;
	int overflow = upper == 1 ? 7 : 39;
	int rem;

	while (num)
	{
		hex = realloc(hex, sizeof(char) * ++len);
		if (!hex)
			return (NULL);
		rem = num % 16;
		if (rem > 9)
		{
			rem = rem + overflow;
		}
		num = num / 16;
		hex[len - 2] = rem + '0';
	}
	hex[len - 1] = '\0';
	rev_string(hex);
	return (hex);
}
