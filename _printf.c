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
int _printf(const char *format, ...)
{
	int count = 0;
	int i, j;
	char *s;

	va_list args;
	va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					s = va_arg(args, char *);
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					for (j = 0; s[j]; j++)
					{
						putchar(s[j]);
						count++;
					}
					break;
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					/**
					 * Handle invalid conversion.
					 */
					putchar((format[i]));
					break;
			}
		}
		else
		{
			write(1, &format[i], sizeof(char));
			count++;
		}
	}
	va_end(args);
	return count;
}
