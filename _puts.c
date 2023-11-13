#include "main.h"

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
