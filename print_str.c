#include "main.h"
#include <unistd.h>
/**
 *  * print_str - Print a string to the buffer
 *   * @buffer: Buffer to print to
 *    * @str: String to print
 * @width: Minimum width of the field
 *  * @precision: Precision for the number of characters to be printed
 *   * @zero_flag: Flag indicating if zero-padding should be used
 *@space_flag: Flag indicating if a space should be
 *added before positive numbers
 * @plus_flag: Flag indicating if a plus sign should be
 * added before positive numbers
 *      * @minus_flag: Flag indicating if left alignment should be used
 *     * Return: Number of characters printed
 */
int print_str(char *buffer, char *str, int width, int precision,
int zero_flag, int space_flag, int plus_flag, int minus_flag)
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
