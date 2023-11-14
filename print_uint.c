#include "main.h"
#include <unistd.h>

/**
 *  * print_uint - Print an unsigned integer to the buffer
 *   * @buffer: Buffer to print to
 *    * @n: Unsigned integer to print
 *     * @width: Minimum width of the field
 *      * @precision: Precision for the number of digits to be printed
 *       * @zero_flag: Flag indicating if zero-padding should be used
 *        * Return: Number of characters printed
 */
int print_uint(char *buffer, unsigned int n,
int width, int precision, int zero_flag)
{
char num_str[12];
int num_len = 0;
int count = 0;
int i;
do	{
num_str[num_len++] = (n % 10) + '0';
n /= 10;
} while (n != 0);
while (num_len < precision)
num_str[num_len++] = '0';
for (i = num_len - 1; i >= 0; i--)
{
buffer[count++] = num_str[i];
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
while (count < width)
{
buffer[count++] = zero_flag ? '0' : ' ';
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
}
}
return (count);
}
