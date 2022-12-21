/*
** EPITECH PROJECT, 2022
** my_put_binary
** File description:
** convert decimal to binary
*/

#include "my.h"

unsigned int my_put_binary(unsigned int nb)
{
    if (nb > 1)
        my_put_binary(nb / 2);
    my_put_nbr(nb % 2);
    nb = nb % 2;
    return (nb);
}
