/**
 *  *  * _puts - Writes a string to standard output
 *   *   * @str: The string to print
 *    *    *
 *     *     * Return: Number of characters written
 */
int _puts(char *str)
{
int count = 0;
if (str)
{
while (str[count])
{
_putchar(str[count]);
count++;
}
}
return (count);
}
