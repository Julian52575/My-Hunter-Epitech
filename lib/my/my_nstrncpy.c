/*
** EPITECH PROJECT, 2022
** N str N cpy
** File description:
** n str n cpy from str to word array
*/

char *my_nstrncpy(char *dest, char const *src, int n, int indice)
{
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[indice];
        i++;
        indice++;
    }
    dest[i] = '\0';
    return dest;
}
