#include "main.h"
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 *  * _printf - Custom printf function
 *   * @format: Format string
 *    * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{

va_list args;
int count = 0, i = 0;
int length_modifier = 0;
int width = 0;
int precision = -1;
int zero_flag = 0;
int space_flag = 0;
int plus_flag = 0;
int hash_flag = 0;
int minus_flag = 0;
int j;
char buffer[BUFFER_SIZE];
char *str;
va_start(args, format);
while (format && format[i])
{
if (format[i] != '%')
{
buffer[count++] = format[i++];
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
else
{
i++;
if (format[i] == '\0')
break;
while (format[i] == 'l' || format[i] == 'h')
{
length_modifier++;
i++;
}
while (format[i] == ' ' || format[i] == '+' || format[i] == '0'
|| format[i] == '#' || format[i] == '-')
{
if (format[i] == ' ')
space_flag = 1;
else if (format[i] == '+')
plus_flag = 1;
else if (format[i] == '0')
zero_flag = 1;
else if (format[i] == '#')
hash_flag = 1;
else if (format[i] == '-')
minus_flag = 1;
i++;
}
if (format[i] >= '0' && format[i] <= '9')
{
width = atoi(format + i);
while (format[i] >= '0' && format[i] <= '9')
i++;
}
if (format[i] == '.')
{
i++;
if (format[i] >= '0' && format[i] <= '9')
{
precision = atoi(format + i);
while (format[i] >= '0' && format[i] <= '9')
i++;
}
}
switch (format[i])
{
case 's':
str = va_arg(args, char *);
count += print_str(buffer + count, str, width, precision,
zero_flag, space_flag, plus_flag, minus_flag);
break;
case 'c':
count += print_char(buffer + count, va_arg(args, int));
break;
case '%':
count += print_percent(buffer + count, width, zero_flag,
space_flag, plus_flag, minus_flag);
break;
case 'd':
case 'i':
count += print_int(buffer + count, va_arg(args, int), length_modifier % 2,
width, precision, zero_flag, space_flag, plus_flag, minus_flag);
break;
case 'u':
count += print_uint(buffer + count, va_arg(args, unsigned int),
width, precision, zero_flag);
break;
case 'o':
count += print_octal(buffer + count, va_arg(args, unsigned int),
width, precision, zero_flag, hash_flag);
break;
case 'x':
count += print_hex(buffer + count, va_arg(args, unsigned int),
0, width, precision, zero_flag, hash_flag, minus_flag);
break;
case 'X':
count += print_hex(buffer + count, va_arg(args, unsigned int),
1, width, precision, zero_flag, hash_flag, minus_flag);
break;
case 'p':count += print_pointer(buffer + count, va_arg(args, void *));
break;
default:
buffer[count++] = '%';
for (j = 0; j < length_modifier; j++)
buffer[count++] = format[i - length_modifier - 1 + j];
buffer[count++] = format[i];
break;
}
i++;
}
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
va_end(args);
if (count > 0)
write(1, buffer, count);
return (count);
}
