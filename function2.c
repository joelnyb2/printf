#include "main.h"
/**
 * print_r - prints astring in reverse
 * @args: string to print
 * Return: number of chars printed
 */
int print_r(va_list args)
{
	char *str;
	int i, count = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = ")Null(";

	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
