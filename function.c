#include "main.h"
#include <stdio.h>
/**
 * _print_char - prints character
 * @args: the va_arg argument
 * Return: count
 */
int _print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}
/**
 * _print_mod - print the % sign
 * @args: the va_arg recieved
 * Return: 1
 */
int _print_mod(va_list args)
{
	char c = '%';

	(void) args;

	write(1, &c, 1);
	return (1);
}
/**
 * _print_string - prints the string char by char
 * @args: arg recieved by the function
 * Return: number of characters printed
 */
int _print_string(va_list args)
{
	int count;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}

	return (count);
}
/**
 * _print_int - prints a decimal integer
 * @args: return the argument
 * Return: the number of printd character
 */
int _print_int(va_list args)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(args, int);

	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
/**
 * _print_binary - prints binary
 * @args: recives va_list value which is in t
 * Return: count
 */
int _print_binary(va_list args)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum = sum + a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
