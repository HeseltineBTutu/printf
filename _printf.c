#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to format.
 *
 * Return: The number of characters to be printed.
 */
#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to format.
 *
 * Return: The number of characters to be printed.
 */
void handle_conversion_specifiers(char specifier, va_list args)
{
	int count = 0;
	char *s;
	int j, num;

	switch (specifier)
	{
		case 'd':
		case 'i':
		{
			num = va_arg(args, int);
			if(num < 0)
			{
				putchar('-');
				num = -num;
			}
			if (num > 9) _printf("d", num/10);
			putchar(num % 10 + '0');
			count++;
			break;
		case 'c':
			putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			s = va_arg(args, char*);
			for (j = 0; s[j]; j++)
			{
				putchar(s[j]);
				count++;
			}
			break;
		case '%':
			putchar('%');
			count++;
			break;
		default:
			putchar(specifier);
			count++;
			break;
		}
	}
}
void write_output(char output)
{
	int count = 0;

	putchar(output);
	count++;
}
void read_format_string(const char *format, va_list args)
{
	int i;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			handle_conversion_specifiers(format[i], args);
		}
		else
		{
			write_output(format[i]);
		}
	}

}

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	read_format_string(format, args);
	va_end(args);
	return (count);
}
