#include "main.h"

char *oct_conv(unsigned int num)
{
	char *oct = NULL;
	unsigned int len = 1;
	int rem;

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
