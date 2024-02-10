#include "main.h"

/**
 * oct_conv - A function to get the octadecimal value of a number
 *
 * @num: The number we want to compute for
 * Return: A string containing the octal value of num
 */

char *oct_conv(unsigned int num)
{
	char *oct = NULL;
	unsigned int len = 1;
	int rem;

	if (num == 0)
	{
		len = 2;
		oct = malloc(sizeof(char) * len);
		if (!oct)
		{
			printf("Malloc of octal number failed\n");
			return (NULL);
		}
		oct[len - 2] = 0 + '0';
	}
	while (num)
	{
		oct = realloc(oct, sizeof(char) * ++len);
		if (!oct)
			return (NULL);
		rem = num % 8;
		num = num / 8;
		oct[len - 2] = rem + '0';
	}
	oct[len - 1] = '\0';
	rev_string(oct);
	return (oct);
}
