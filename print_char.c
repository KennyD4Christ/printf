#include "main.h"
#include <unistd.h>

/**
 *  * print_char - Print a character to the buffer
 *   * @buffer: Buffer to print to
 *    * @c: Character to print
 *     * Return: Number of characters printed
 */
int print_char(char *buffer, int c)
{
int count = 0;
buffer[count++] = c;
return (count);
}

