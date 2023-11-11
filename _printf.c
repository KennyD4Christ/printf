#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 *  * _printf - Custom printf function
 *   * @format: Format string with directives
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (format && format[count])
{
if (format[count] == '%' && format[count + 1])
{
if (format[count + 1] == 'c')
count += _putchar(va_arg(args, int));
else if (format[count + 1] == 's')
count += _puts(va_arg(args, char *));
else if (format[count + 1] == '%')
count += _putchar('%');
else
{
_putchar(format[count]);
_putchar(format[count + 1]);
count += 2;
continue;
}
count += 2;
continue;
}
_putchar(format[count]);
count++;
}
va_end(args);
return (count);
}
/**
 *  * _putchar - Writes a character to standard output
 *   * @c: The character to print
 *    *
 *     * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 *  * _puts - Writes a string to standard output
 *   * @str: The string to print
 *    *
 *     * Return: Number of characters written
 */
int _puts(char *str)
{
int count = 0;
if (str)
{
while (*str)
{
_putchar(*str);
count++;
str++;
}
}
return (count);
}
