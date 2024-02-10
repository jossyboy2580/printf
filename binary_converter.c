#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * bin_conv - A function to get the octadecimal value of a number
 * @num: The number we want to compute for
 * Return: A string containing the octal value of num
 */

char *bin_conv(unsigned int num)
{
	char *bin = NULL;
	unsigned int len = 1;
	unsigned int rem;



	if (num == 0)
	{
		len = 2;
		bin = malloc(sizeof(char) * len);
		if (!bin)
		{
			printf("Malloc of binary number failed\n");
			return (NULL);
		}
		bin[len - 2] = 0 + '0';
	}
	else
	{
		while (num)
		{
			bin = realloc(bin, sizeof(char) * ++len);
			if (!bin)
			{
				printf("Realloc failed\n");
				return (NULL);
			}
			rem = num % 2;
			num = num / 2;
			bin[len - 2] = rem + '0';
		}
	}
	bin[len -1] = '\0';
	rev_string(bin);
	return (bin);
}
