/*
** EPITECH PROJECT, 2022
** my str to word array
** File description:
** Flat str becomes huge array
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_put_array(char **array, char del);

char **my_str_to_word_array(char const *str)
{
    int a = 0;
    int s = 0;
    char **array = malloc(my_strlen(str) * 10);
    char *string = malloc(my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == ' ') {
            string[s++] = '\0';
            array[a] = malloc(my_strlen(string) + 1);
            my_strcpy(array[a++], string);

            free(string);
            string = malloc(my_strlen(str + i));
            s = 0;
            continue;
        } string[s++] = str[i];
    } string[s] = '\0';
    array[a++] = string;
    array[a] = "\0";
    return array;
}
