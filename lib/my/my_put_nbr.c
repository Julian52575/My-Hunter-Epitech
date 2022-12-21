/*
** EPITECH PROJECT, 2022
** put nbr
** File description:
** print a int
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 10)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (nb);
}
