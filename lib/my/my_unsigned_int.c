/*
** EPITECH PROJECT, 2022
** put nbr
** File description:
** print a unsigned int
*/

#include "my.h"

unsigned int my_unsigned_int(unsigned int nb)
{
    if (nb < 10)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (nb);
}
