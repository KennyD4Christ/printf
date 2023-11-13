#include "main.h"

/* Function prototypes */
int _putchar(int c);
int _puts(char *str);
char *itoa(int num);

/**
 *  * _printf - Custom printf function
 *   * @format: Format string containing directives
 * Return: Number of characters printed (excluding null byte) or -1 on error
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
case 'd':
case 'i':
{
int num = va_arg(args, int);
int temp_count = 0;
if (num < 0)
{
temp_count += _putchar('-');
num = -num;
}
temp_count += _puts(itoa(num));
if (temp_count == -1)
{
va_end(args);
return (-1);
}
count += temp_count;
}
break;
default:
if (_putchar(*format) == -1)
{
va_end(args);
return (-1);
}
count++;
break;
}
}
else
{
if (_putchar(*format) == -1)
{
va_end(args);
return (-1);
}
count++;
}
format++;
}
va_end(args);
return (count);
}
/**
 *  * _putchar - Custom putchar function
 *   * @c: Character to print
 *    * Return: On success, the number of characters written; On error, -1
 */
int _putchar(int c)
{
return (write(1, &c, 1));
}
/**
 *  * _puts - Custom puts function
 *   * @str: String to print
 * Return: Number of characters printed (excluding null byte) or -1 on error
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
 *  * itoa - Convert an integer to a string
 *   * @num: Integer to convert
 *    * Return: String representation of the integer
 */
char *itoa(int num)
{
static char buffer[12];
int i = 0;
int start = 0;
int end = i - 1;
if (num == 0)
{
buffer[i++] = '0';
}
else
{
if (num < 0)
{
buffer[i++] = '-';
num = -num;
}
do
{
buffer[i++] = '0' + (num % 10);
num /= 10;
}
while (num != 0);
}
buffer[i] = '\0';
while (start < end)
{
char temp = buffer[start];
buffer[start] = buffer[end];
buffer[end] = temp;
start++;
end--;
}
return (buffer);
}
