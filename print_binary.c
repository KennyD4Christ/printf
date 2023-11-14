#include "main.h"

/**
 *  * print_binary - Print a binary number to the buffer
 *   * @buffer: Buffer to print to
 *    * @n: Binary number to print
 *     * @width: Minimum width of the field
 *      * @precision: Precision for the number of digits to be printed
 *       * @zero_flag: Flag indicating if zero-padding should be used
 *        * Return: Number of characters printed
 */
int print_binary(char *buffer, unsigned int n,
int width, int precision, int zero_flag)
{
char binary_str[32];
int binary_len = 0;
int count = 0;
int i;
do	{
binary_str[binary_len++] = (n % 2) + '0';
n /= 2;
} while (n != 0);
while (binary_len < precision)
binary_str[binary_len++] = '0';
for (i = binary_len - 1; i >= 0; i--)
{
buffer[count++] = binary_str[i];
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
