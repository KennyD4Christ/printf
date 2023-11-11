#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
while (format && format[count])
{
if (format[count] == '%' && format[count + 1] != '\0')
{
switch (format[count + 1])
{
case 'c':
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
break;
}
case 's':
write(1, va_arg(args, char *), 1);
break;
case '%':
write(1, "%", 1);
break;
default:
write(1, "%", 1);
break;
}
count += 2;
}
else
{
write(1, &format[count], 1);
count++;
}
}
va_end(args);
return (count);
}
