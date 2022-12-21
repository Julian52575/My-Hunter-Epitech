/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Count the number of character in a string
*/

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' ; i++) {
        count++;
    }
    return (count);
}
