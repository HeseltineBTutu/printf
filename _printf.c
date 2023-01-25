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
    va_list args;
    int count = 0;
    int i;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'd' || format[i] == 'i') {
                int num = va_arg(args, int);
                if(num<0) 
                {
                    putchar('-');
                    num = -num;
                }
                if(num>9) _printf("%d",num/10);
                putchar(num%10+'0');
                count++;
            } else if (format[i] == 's') {
                char *str = va_arg(args, char *);
                while(*str)
                {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (format[i] == '%') {
                count += putchar('%');
            } else {
                count += putchar(format[i]);
            }
        } else {
            count += putchar(format[i]);
        }
    }
    va_end(args);
    return count;
}
