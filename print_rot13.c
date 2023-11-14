#include "main.h"
#include <string.h>

/**
 *  * print_rot13 - Print a rot13'ed string to the buffer
 *   * @buffer: Buffer to print to
 *    * @str: String to print
 *     * Return: Number of characters printed
 */
int print_rot13(char *buffer, char *str)
{
int i;
if (!str)
str = "(null)";
for (i = 0; str[i]; i++)
{
char c = str[i];
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
c = (c <= 'Z') ? ((c - 'A' + 13) % 26 + 'A') : ((c - 'a' + 13) % 26 + 'a');
}
buffer[i] = c;
}
write(1, buffer, strlen(buffer));
return (strlen(buffer));
}
