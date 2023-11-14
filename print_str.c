#include "main.h"
#include <unistd.h>
/**
 *  * print_str - Print a string to the buffer
 *   * @buffer: Buffer to print to
 *    * @str: String to print
 *     * Return: Number of characters printed
 */
int print_str(char *buffer, char *str, int width, int precision, int zero_flag, int space_flag, int plus_flag, int minus_flag)
{
int i, count = 0;
(void)width;
(void)precision;
(void)zero_flag;
(void)space_flag;
(void)plus_flag;
(void)minus_flag;
if (!str)
str = "(null)";
for (i = 0; str[i]; i++)
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
