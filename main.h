#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_str(char *buffer, char *str, int width, int precision, int zero_flag, int space_flag, int plus_flag, int minus_flag);
int print_char(char *buffer, int c);
int print_percent(char *buffer, int width, int zero_flag, int space_flag, int plus_flag, int minus_flag);
int print_int(char *buffer, int n, int is_negative, int width, int precision, int zero_flag, int space_flag, int plus_flag, int minus_flag);
int print_uint(char *buffer, unsigned int n, int width, int precision, int zero_flag);
int print_octal(char *buffer, unsigned int n, int width, int precision, int zero_flag, int hash_flag);
int print_hex(char *buffer, unsigned int n, int is_upper, int width, int precision, int zero_flag, int hash_flag, int minus_flag);
int print_binary(char *buffer, unsigned int n, int width, int precision, int zero_flag);
int print_str_non_printable(char *buffer, char *str);
int print_rev(char *buffer, char *str);
int print_rot13(char *buffer, char *str);
int print_pointer(char *buffer, void *ptr);
#endif /* MAIN_H */
