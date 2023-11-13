#include "main.h"

int _putchar(int c);
int _puts(char *str);

/**
 *  * _printf - Custom printf function
 *   * @format: Format string containing directives
 *    * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
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
case '%':
count += _putchar('%');
break;
default:
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
 *    * Return: 1 on success, -1 on error
 */
int _putchar(int c)
{
return (write(1, &c, 1));
}
/**
 *  * _puts - Custom puts function
 *   * @str: String to print
 *    * Return: Number of characters printed (excluding null byte)
 */
int _puts(char *str)
{
int count = 0;
if (str == NULL)
return (_puts("(null)"));
while (*str)
{
if (_putchar(*str) == -1)
return (-1);
count++;
str++;
}
return (count);
}
