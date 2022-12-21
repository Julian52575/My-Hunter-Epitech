/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** include
*/

#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct flag {
    int count;
    int i;
    int order;
    int space;
    int plus;
    int blank;
    int hashtag;
    long width;
    long precision;
    long position;
    int distance;
    int nb;
};

typedef struct flag flag;

flag check_flags(flag flags, char c);
int printf_analyze(va_list ap, char* string, flag flags);
int check_valid_type(va_list ap, char t);
flag printf_percent(va_list ap, const char* format, flag flags);
int printf_int(va_list ap, char *string, flag flags);
int printf_char(va_list ap, char *string, flag flags);
int printf_string(va_list ap, char *string, flag flags);
int printf_n(va_list ap, char *string, flag flags);
int printf_width(va_list ap, char *string, flag flags);
int printf_type(va_list ap, char *string, flag flags);
int printf_double(va_list ap, char *string, flag flags);
int get_precision(char *string, flag flags);
flag get_width(char *string, flag flags);
int printf_o(va_list ap, char *string, flag flags);
int printf_expo(va_list ap, char *string, flag flags);
int printf_u(va_list ap, char *string, flag flags);
flag printf_flags(char *string, flag flags);
int printf_b(va_list ap, char *string, flag flags);
int printf_expo_up(va_list ap, char *string, flag flags);
void put_expo_up(double db, int count, int precision);
int my_put_exponential_up(double db, int precision);
