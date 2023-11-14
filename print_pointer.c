#include "main.h"
#include <unistd.h>
#include <stdint.h>
/**
 *  * print_pointer - Print a pointer address to the buffer
 *   * @buffer: Buffer to print to
 *    * @ptr: Pointer to print
 *     * Return: Number of characters printed
 */
int print_pointer(char *buffer, void *ptr)
{
uintptr_t address = (uintptr_t)ptr;
int temp;
char hex_digit;
int count = 0;
int i;
int leading_zeros = 1;
buffer[count++] = '0';
buffer[count++] = 'x';
for (i = sizeof(void *) * 2 - 1; i >= 0; i--)
{
temp = (address >> (i * 4)) & 0xF;
if (temp == 0 && leading_zeros)
continue;
leading_zeros = 0;
hex_digit = (temp < 10) ? (temp + '0') : (temp - 10 + 'a');
buffer[count++] = hex_digit;
}
if (leading_zeros)
buffer[count++] = '0';
return (count);
}
