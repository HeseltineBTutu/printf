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
	int i;
	char c;

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
					c = va_arg(args, int);
					write(1, &c, sizeof(int));
					count++;
					break;
				case 's':
					write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
					count += strlen(va_arg(args, char *));
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					/**
					 * Handle invalid conversion.
					 */
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
	
