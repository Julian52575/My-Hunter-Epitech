/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p);
int get_unit(int nb);
int my_getnbr(char *str);
int my_isneg(int nb);
int my_put_double(double db, long precision);
void put_expo(double db, int count, int precision);
int my_put_exponential(double db, int precision);
int my_put_float(float fl, long precision);
int my_put_nbr(int nb);
unsigned int my_put_octal(unsigned int nb);
void my_putchar(char c);
int my_putstr (char const *str);
int my_str_to_int(char *str);
int is_char(char c);
int count_lines(char const *str);
int get_word(char const *str, int index, char *arr);
char **my_str_to_word_array(char const *str);
char *my_strcpy (char *dest, char const *src);
int my_strlen(char const *str);
void my_swap(int *a, int *b);
unsigned int my_unsigned_int(unsigned int nb);
unsigned int my_put_binary(unsigned int nb);
char **my_str_to_word_array(char const *str);
void my_put_array(char **array, char del);
int my_is_alpha(char *str1, char *str2);
int my_putstr(char const *str);
int get_1st_digit(int nb);
int get_2nd_digit(int nb);
int get_3rd_digit(int nb);
