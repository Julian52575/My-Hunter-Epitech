/*
** EPITECH PROJECT, 2022
** my_put_array
** File description:
** display an array
*/
void my_putchar(char c);

void my_put_array(char **array, char del)
{
    for (int y = 0; array[y][0] != '\0'; y++) {
        for (int x = 0; array[y][x] != '\0'; x++) {
            my_putchar(array[y][x]);
        }
        my_putchar(del);
    }
}
