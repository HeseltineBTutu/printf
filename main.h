#ifndef PRINTF_H
#define PRINTF_H
int _printf(const char *format, ...);
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define bool int
#define true 1
#define false 0
int _printf(const char *, ...);
char *convert(unsigned int num, int base, bool upper);
int print_string(const char *s);
#endif
