#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


struct conv
{
	char *sym;
	int (*f)(va_list);
};
typedef struct conv conv_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_String(va_list list);
int print_point(va_list list);
int peep(const char *format, conv_t form_list[], va_list prt);
int print_char(va_list list);
int print_str(va_list list);
int print_per(__attribute__((unused))va_list list);
int print_int(va_list list);
int unsigned_int(va_list list);
int print_number(va_list args);
int print_unsigned_num(unsigned int n);
int hexa_check(int, char);
int print_binary(va_list list);
int print_oct(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int print_rev(va_list arg);
int rot13(va_list list);
/* functions */
void write_base(char *str);
unsigned int base_length(unsigned int num, int base);
char *rev_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
void print_buffer(char buffer[], int *buff_ind);

#endif
