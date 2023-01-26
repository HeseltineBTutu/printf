#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to format.
 *
 * Return: The number of characters to be printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;

    va_start(args, format);
    while (*format != '\0')
    {
	    if (*format == '%')
	    {
		    format++;
		    if (*format == 'c')
		    {
			    putchar(va_arg(args, int));
			    count++;
		    }
		    else if (*format == 's')
		    {
			    str = va_arg(args, char *);
			    printf("%s", str);
			    count += strlen(str);
		    }
		    else if (*format == 'd' || *format == 'i')
		    {
			    count += printf("%d", va_arg(args, int));
		   }
		    else if (*format == 'u')
		    {
			    count += printf("%u", va_arg(args, unsigned int));
		    }
		    else if (*format == 'o')
		    {
			    count += printf("%o", va_arg(args, unsigned int));
		    }
		    else if (*format == 'x')
		    {
			    count += printf("%x", va_arg(args, unsigned int));
		    }
		    else if (*format == 'X')
		    {
			    count += printf("%X", va_arg(args, unsigned int));
		    }
		    else if (*format == 'p')
		    {
			    count += printf("%p", va_arg(args, void *));
		    }
		    else if (*format == 'r')
		    {
			    printf("%r");
			    count += 1;
		    }
		    else if (*format == '%')
		    {
			    putchar('%');
			    count++;
		    }
	    }
	    else
	    {
		    putchar(*format);
		    count++;
	    }
	    format++;
    }
    va_end(args);
    return count;
}
