#include "main.h"
#include <stdio.h>
/**
 * _printf - takes arguments and prints them
 * @format: the first string containing %
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int i, j;
	int count = 0;
	va_list args;

	argument id_s[] = {{'c', _print_char}, {'s', _print_string},
		{'i', _print_int}, {'b', _print_binary}, {'u', print_u},
		{'o', print_o}, {'x', print_x}, {'X', print_X}, {'p', print_p},
		 {'S', print_S}, {'r', print_r}, {'R', print_R},
		 {'d', _print_int}, {'%', _print_mod}, {'\0', NULL}
	};


	va_start(args, format);
	for (i = 0; format[i]; i++)

		if (format[i] == '%')
		{
			i++;
			for (; format[i] != '\0'; i++)
			{
				for (j = 0; id_s[j].id != '\0'; j++)
					if (format[i] == id_s[j].id)
					{
						count = count + id_s[j].fun(args);
						break;
					}
				if (id_s[j].id)
					break;
			}
			if (format[i] == '\0')
				return (-1);


		}
		else
		{
			write(1, &format[i], 1);
			count = count + 1;
		}
	va_end(args);
	return (count);


}
