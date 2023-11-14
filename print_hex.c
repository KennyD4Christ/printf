#include "main.h"

/**
 *  * print_hex - Print a hexadecimal number to the buffer
 *   * @buffer: Buffer to print to
 *    * @n: Hexadecimal number to print
 *     * @is_upper: Flag indicating if uppercase letters should be used
 *      * @width: Minimum width of the field
 *       * @precision: Precision for the number of digits to be printed
 *        * @zero_flag: Flag indicating if zero-padding should be used
 *@hash_flag: Flag indicating if the hex prefix '0x' or '0X' should be used
 *          * Return: Number of characters printed
 */
int print_hex(char *buffer, unsigned int n, int is_upper, int width, int precision, int zero_flag, int hash_flag, int minus_flag)
{
char hex_chars[] = "0123456789abcdef";
int hex_len = 0;
char hex_str[12];
int count = 0;
int i;
(void)minus_flag;
do	{
hex_str[hex_len++] = hex_chars[n % 16];
n /= 16;
} while (n != 0);
while (hex_len < precision)
hex_str[hex_len++] = '0';
if (hash_flag)
{
hex_str[hex_len++] = '0';
hex_str[hex_len++] = is_upper ? 'X' : 'x';
}
for (i = hex_len - 1; i >= 0; i--)
{
buffer[count++] = is_upper ? toupper(hex_str[i]) : hex_str[i];
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
