#include "main.h"

/**
 *  * print_octal - Print an octal number to the buffer
 *   * @buffer: Buffer to print to
 *    * @n: Octal number to print
 *     * @width: Minimum width of the field
 *      * @precision: Precision for the number of digits to be printed
 *       * @zero_flag: Flag indicating if zero-padding should be used
 *        * @hash_flag: Flag indicating if the octal prefix '#' should be used
 *         * Return: Number of characters printed
 */
int print_octal(char *buffer, unsigned int n, int width,
int precision, int zero_flag, int hash_flag)
{
char octal_str[12];
int octal_len = 0;
int count = 0;
int i;
do	{
octal_str[octal_len++] = (n % 8) + '0';
n /= 8;
} while (n != 0);
if (octal_len == 0)
{
octal_str[octal_len++] = '0';
}
while (octal_len < precision)
octal_str[octal_len++] = '0';
if (hash_flag)
{
octal_str[octal_len++] = '0';
}
for (i = octal_len - 1; i >= 0; i--)
{
buffer[count++] = octal_str[i];
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
