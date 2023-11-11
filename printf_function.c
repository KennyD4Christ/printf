#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
switch (format[count + 1])
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
