#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *  * _printf - Custom printf function with limited functionality.
 *   * @format: Format string containing directives.
 *    *
 *     * Return: (count) - The number of characters printed
 *     (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%' && *(format + 1) != '\0')
{
format++;
switch (*format)
{
case 'c':
count += (putchar(va_arg(args, int)));
break;
case 's':
count += (puts(va_arg(args, char *)));
break;
case '%':
count += (putchar('%'));
break;
default:
count += (putchar('%'));
count += (putchar(*format));
break;
}
}
else
{
count += (putchar(*format));
}
format++;
}
va_end(args);
return (count);
}
