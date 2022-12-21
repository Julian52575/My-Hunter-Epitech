/*
** EPITECH PROJECT, 2022
** Str to int
** File description:
** no more str
*/

#include "my.h"

int my_str_to_int(char *str)
{
    long nb = 0;
    int len = my_strlen(str);
    for (int i = 0; i <= len; i++)
        nb += ((str[i] - 48) * my_compute_power_rec(10, len - 1 - i));
    return nb;
}
