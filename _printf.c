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
	va_list args;
	int i;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						char c = (char)va_arg(args, int);

						write(1, &c, 1);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);
						int len =strlen(s);
						char *str = (char *)malloc(len + 1);

						strcpy(str, s);

						write(1, str, len);
						count += len;
						break;
					}
				case '%':
					{
						char c = '%';

						write(1, &c, 1);
						count++;
						break;
					}
				default:
					{
						char c = format[i];

						write(1, &c, 1);
						count++;
						break;
					}
			}
		}
		else
		{
			char c = format[i];

			write(1, &c, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
