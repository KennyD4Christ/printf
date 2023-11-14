#include "main.h"
#include <unistd.h>

/**
 *  * print_str_non_printable - Print a string with non-printable characters
 *   * @buffer: Buffer to print to
 *    * @str: String to print
 *     * Return: Number of characters printed
 */
int print_str_non_printable(char *buffer, char *str)
{
int count = 0;
int i;
if (!str)
str = "(null)";
for (i = 0; str[i]; i++)
{
if (str[i] < ' ' || str[i] >= 127)
{
buffer[count++] = '\\';
buffer[count++] = 'x';
buffer[count++] = (str[i] / 16) < 10 ? (str[i] / 16) + '0' :
(str[i] / 16) - 10 + 'A';
buffer[count++] = (str[i] % 16) < 10 ? (str[i] % 16) + '0' :
(str[i] % 16) - 10 + 'A';
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
else
{
buffer[count++] = str[i];
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
}
return (count);
}
