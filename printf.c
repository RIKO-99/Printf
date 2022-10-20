#include "main.h"

/**
 * _printf - prints argument passed
 * @format: variable number of arguments
 * of diffrent types
 *
 * Return: the standard output stream
 * number of characters printed
 */
int _printf(const char *format, ...)
{
	char *p, *sval;
	int ival;

	va_list ap; /*points to each unamed arguments*/

	va_start(ap, format); /*points to first argument*/

	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				ival = va_arg(ap, int);
				putchar(ival);
				ival++;
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
