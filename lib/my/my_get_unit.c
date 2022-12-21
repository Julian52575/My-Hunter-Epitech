/*
** EPITECH PROJECT, 2022
** get_unit
** File description:
** lenth of an int
*/

int get_unit(int nb)
{
    if (nb < 9)
        return 1;
    else
        return 1 + get_unit(nb / 10);
}
