#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct arguments - interface for printing
 * @id: the character that determines the specifier
 * @fun: function pointer
 */
typedef struct arguments
{
	char id;
	int (*fun)(va_list);
} argument;

int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_mod(va_list args);
int _print_string(va_list args);
int _print_int(va_list args);
int _print_binary(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int _putchar(char args);
int print_S(va_list args);
int print_p(va_list args);
int print_r(va_list args);
int print_R(va_list args);



#endif
