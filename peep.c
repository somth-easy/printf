#include "main.h"
/**
 * peep - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @form_list: A list of all the posible functions.
 * @prt: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int peep(const char *format, conv_t form_list[], va_list prt)
{
	int x, y, ret_v, print_chars;

	print_chars = 0;
	for (x = 0; format[x] != '\0'; x++)/* Iterates through the main str*/
	{
		if (format[x] == '%') /*Checks for format specifiers*/
		{
			y = 0;
			while (form_list[y].sym != NULL)
			{
				if (format[x + 1] == form_list[y].sym[0])
				{
					ret_v = form_list[y].f(prt);
					if (ret_v == -1)
						return (-1);
					print_chars += ret_v;
					break;
				}
				y++;
			}
			if (form_list[y].sym == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					_putchar(format[x]);
					_putchar(format[x + 1]);
					print_chars += 2;
				}
				else
					return (-1);
			}
			x += 1; /*Updating x to skip format symbols*/
		}
		else
		{
			_putchar(format[x]);
			print_chars++;
		}
	}
	return (print_chars);
}
