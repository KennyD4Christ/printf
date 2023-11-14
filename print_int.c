#include "main.h"

/**
 *  * print_int - Print an integer to the buffer
 *   * @buffer: Buffer to print to
 *    * @n: Integer to print
 *     * @is_negative: Flag indicating if the integer is negative
 *      * @width: Minimum width of the field
 *       * @precision: Precision for the number of digits to be printed
 *        * @zero_flag: Flag indicating if zero-padding should be used
 *         * Return: Number of characters printed
 */
int print_int(char *buffer, int n, int is_negative, int width, int precision, int zero_flag, int space_flag, int plus_flag, int minus_flag)
{
char num_str[12];
int num_len = 0;
int count = 0;
int i;
if (is_negative)
{
buffer[count++] = '-';
n = -n;
}
else if (plus_flag)
{
buffer[count++] = '+';
}
else if (space_flag)
{
buffer[count++] = ' ';
}
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
if (minus_flag)
{
while (count < width)
{
buffer[count++] = ' ';
if (count == BUFFER_SIZE)
{
write(1, buffer, count);
count = 0;
if (count > 0)
{
write(1, buffer, count);
}
}
}
}
return (count);
}
