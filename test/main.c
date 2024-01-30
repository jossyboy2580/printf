#include "main.h"

int main(void)
{
	int count;

	count = _printf("My name is %s i am %d years old\n", "Joseph", 28);
	count = _printf("My birth month first letter is %c\n", 'M');
	count = _printf("This is a single percent sign: %%\n");
	return (0);
}
