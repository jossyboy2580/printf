#include "main.h"

char *hex_conv(unsigned int num, int upper)
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
