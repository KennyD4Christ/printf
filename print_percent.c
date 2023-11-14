#include "main.h"
#include <unistd.h>

/**
 *  * print_percent - Print a percent character to the buffer
 *   * @buffer: Buffer to print to
 *    * @width: Minimum width
 *     * @zero_flag: Whether to pad with zeros
 *      * @space_flag: Unused for '%', included for consistency
 *       * @plus_flag: Unused for '%', included for consistency
 *        * @minus_flag: Whether to left-justify the output
 *         * Return: Number of characters printed
 */
int print_percent(char *buffer, int width, int zero_flag,
int space_flag, int plus_flag, int minus_flag)
{
int count = 0;
int i;
(void)space_flag;
(void)plus_flag;
if (width > 1 && !minus_flag)
{
char pad_char = zero_flag ? '0' : ' ';
for (i = 1; i < width; i++)
buffer[count++] = pad_char;
}
buffer[count++] = '%';
if (width > 1 && minus_flag)
{
for (i = 1; i < width; i++)
buffer[count++] = ' ';
}
return (count);
}

