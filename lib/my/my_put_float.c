/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** print float
*/

#include "my.h"

int my_put_float(float fl, long precision)
{
    double db = fl;
    int nb = fl;

    my_put_nbr(nb);
    my_putchar('.');
    while (precision > 0) {
        db *= 10;
        nb = db;
        nb = nb % 10;
        my_put_nbr(nb);
        precision -= 1;
    }
    return 1;
}
