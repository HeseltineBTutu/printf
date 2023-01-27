#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to format.
 *
 * Return: The number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	const char *traverse;
	signed int i;
	char *s;
	int count = 0;
	unsigned long int p;

	va_list arg;
	va_start(arg, format);

	for (traverse = format; *traverse != '\0'; traverse++)
	{
		if (*traverse != '%')
		{
			write(1, traverse, 1);
			count++;
			continue;
		}
		traverse++;
		switch(*traverse)
		{
			case 'c' : i = va_arg(arg, int);
				   write(1, &i, 1);
				   count++;
				   break;
			case 'd' : i = va_arg(arg, int);
				   if (i < 0)
				   {
					   i = -i;
					   write(1, "-", 1);
					   count++;
				   }
				   count += print_string(convert(i, 10));
				   break;
			case 'o' : i = va_arg(arg, unsigned int);
				   count += print_string(convert(i, 8));
				   break;
			case 's' : s = va_arg(arg, char *);
				   if (!s)
				   {
					   s = "(null)";
				   }
				   count += print_string(s);
				   break;
			case 'i' :
				   i = va_arg(arg, int);
				   if (i < 0)
				   {
					   i = -i;
					   write(1, "-", 1);
					   count++;
				   }
				   count += print_string(convert(i, 10));
				   break;
			case 'l' :
				   i = va_arg(arg, long int);
				   if (i <0)
				   {
					   i = -i;
					   write(1, "-", 1);
					   count++;
				   }
				   count +=print_string(convert(i, 10));
				   break;
			case 'x' :
				   i = va_arg(arg, unsigned int);
				   count += print_string(convert_hex(i, 16, 0));
				   break;
			case 'X' :
				   i = va_arg(arg, unsigned int);
				   count += print_string(convert_hex(i, 16, 1));
				   break;

			case 'u' :
				   i = va_arg(arg, unsigned int);
				   count += print_string(convert(i, 10));
				   break;
			case 'p':
				   p = (unsigned long int) va_arg(arg, void *);
				   count += print_string("%x");
				   count += print_string(convert(p, 16));
				   break;
			case '\0' :
				   return (-1);
				   break;
			case '%':
				   write(1, "%", 1);
				   count++;
				   break;
			default:
			   write(1, "%", 1);
			   write(1, traverse, 1);
			   count += 2;
			   break;
		}
	}
	va_end(arg);
	return (count);
}
int print_string(const char *s)
{
int count = 0;
int len = strlen(s);
int ret = write(1, s, len);
if (ret > 0)
	count += ret;
return (count);
}
char *convert(unsigned int num, int base)
{
static char Representation[] = "0123456789ABCDEF";
static char buffer[50];
char *ptr;
int count = 0;

ptr = &buffer[49];
*ptr = '\0';
count++;
do
{
	*--ptr = Representation[num % base];
	num /= base;
}
while (num != 0);
return (ptr);
}
char *convert_hex(unsigned int num, int base, int uppercase)
{
    static char Representation[] = "0123456789abcdef";
    static char buffer[50];
    char *ptr;
    if (uppercase) {
        Representation[10] = 'A';
        Representation[11] = 'B';
        Representation[12] = 'C';
        Representation[13] = 'D';
        Representation[14] = 'E';
        Representation[15] = 'F';
    }
    ptr = &buffer[49];
    *ptr = '\0';
    do
    {
        *--ptr = Representation[num % base];
        num /= base;
    }
    while (num != 0);

    return (ptr);
}
