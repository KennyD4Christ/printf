#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *  * _printf - Custom printf function
 *   * @format: Format string containing directives
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (format && *format)
{
if (*format == '%' && *(format + 1) != '\0')
{
format++;
switch (*format)
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
count += _puts(va_arg(args, char *));
break;
case 'd':
case 'i':
count += _print_int(va_arg(args, int));
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(*format);
break;
}
}
else
{
count += _putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
/**
 *  * _putchar - Custom putchar function
 *   * @c: Character to print
 *    *
 *     * Return: 1 on success, -1 on error
 */
int _putchar(int c)
{
return (write(1, &c, 1));
}
/**
 *  * _puts - Custom puts function
 *   * @str: String to print
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 */
int _puts(char *str)
{
int count = 0;
if (str == NULL)
str = "(null)";
while (*str)
{
if (_putchar(*str) == -1)
return (-1);
count++;
str++;
}
return (count);
}
/**
 *  * _print_int - Custom function to print integers
 *   * @n: Integer to print
 *    *
 *     * Return: Number of characters printed
 */
int _print_int(int n)
{
int count = 0;
/* Assuming that int can be represented as 10 characters at most */
char buffer[11];
int i = 0;
/* Handle negative numbers */
if (n < 0)
{
count += _putchar('-');
n = -n;
}
/* Convert integer to string in reverse order */
do	{
buffer[i++] = n % 10 + '0';
n /= 10;
}	while (n != 0);
/* Print the reversed string */
while (--i >= 0)
{
count += _putchar(buffer[i]);
}
return (count);
}
