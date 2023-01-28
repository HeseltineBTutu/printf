#ifndef PRINTF_H
#define PRINTF_H
int _printf(const char *format, ...);
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *, ...);
char *convert(unsigned int num, int base);
int print_string(const char *s);
#endif
