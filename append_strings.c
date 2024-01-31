#include "main.h"

/**
 * str_len - A function to determine the length of a null terminated
 * string
 *
 * @str: The string whose length we want to determine
 * Return:: an unsigned value of the length of the string
 */

unsigned int str_len(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * append_string - A function to append a small string to the buffer
 *
 * @str1: The buffer to which we want to add the smaller string
 * @str2: the smaller string we want to add to the buffer
 */

void append_string(char **str1, char *str2)
{
	unsigned int len_str2, len_str1;
	unsigned int i;

	if (str2 == NULL)
		return;
	if (*str1 == NULL)
		len_str1 = 0;
	else
		len_str1 = str_len(*str1);
	len_str2 = str_len(str2);
	*str1 = realloc(*str1, sizeof(char) * (len_str1 + len_str2 + 1));
	if (!*str1)
	{
		free(*str1);
		return;
	}
	for (i = 0; i < len_str2; i++)
	{
		(*str1)[i + len_str1] = str2[i];
	}
	(*str1)[i + len_str1] = '\0';
}

/**
 * append_char - A function to append a single character to a string
 *
 * @str1: The string to which we want to append the character
 * @c: the chatacter we want to append to the string
 */

void append_char(char **str1, char c)
{
	unsigned int len_str1 = 0;

	if (*str1 != NULL)
		len_str1 = str_len(*str1);
	*str1 = realloc(*str1, sizeof(char) * (len_str1 + 2));
	(*str1)[len_str1] = c;
	(*str1)[len_str1 + 1] = '\0';
}


/**
 * rev_string - Reverse a string with this function
 * @s: The string we want to reverse
 */ 

void rev_string(char *s)
{
	int len = 0, i, half;
	char temp;

	while (s[len] != '\0')
		len++;

	half = len / 2;
	if (len % 2 != 0)
		half = (len - 1) / 2;
	for (i = 0; i < half; i++)
	{
		temp = *(s + i);
		*(s + i) = *(s + (len - (i + 1)));
		*(s + (len - (i + 1))) = temp;
	}
}
