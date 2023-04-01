#include "main.h"

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; (num / div) > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * print_unsigned_num - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsigned_num(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; (num / div) > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_rev - Calls a function to reverse and print a string
 * @list: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_rev(va_list list)
{
	int length, count = 0;
	char *string = va_arg(list, char *);

	length = strlen(string) - 1;
	if (string == NULL)
	{
		return (-1);
	}
	while (length >= 0)
	{
		_putchar(*(string + length));
		length--;
		count++;
	}
	return (count);
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
int rot13(va_list list)
{
	int a;
	int b;
	char *str;
	char v[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (a = 0; str[a] != '\0'; a++)
	{
		for (b = 0; b <= 52; b++)
		{
			if (str[a] == v[b])
			{
				_putchar(u[b]);
				break;
			}
		}
		if (b == 53)
			_putchar(str[a]);
	}
	return (a);
}
