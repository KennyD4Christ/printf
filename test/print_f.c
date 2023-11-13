#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: the format specified
 * Return: the number of char in the string
 */

int _printf(const char *format, ...)
{
	int strlen;
	va_list args;
	
	strlen = 0;
	va_start(args, format);
	while(*format)
	{
		if(*format != '%')
		{
			_putchar(*format);
			strlen++;
		}

		else
		{
			format++;

			if (*format == 'c')
			{
				_putchar((char)(va_arg(args, int)));
				strlen++;
			}

			if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					strlen++;
				}
			
			}

			if (*format == '%')
			{
				_putchar('%');
				strlen++;
			}

			
		}
		format++;

		
	}

	return (strlen);
}
