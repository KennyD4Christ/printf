#include "main.h"
#include <unistd.h>

/**
 *  * print_rev - Print a reversed string to the buffer
 *   * @buffer: Buffer to print to
 *    * @str: String to print
 *     * Return: Number of characters printed
 */
int print_rev(char *buffer, char *str)
{
int i, count = 0;
if (!str)
str = "(null)";
for (i = 0; str[i]; i++)
;
for (i--; i >= 0; i--)
{
buffer[count++] = str[i];
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
return (count);
}
