/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** close_window
*/
#include "my_csfml.h"

void close_window(sfRenderWindow *w, sfEvent e)
{
    while (sfRenderWindow_pollEvent(w, &e) == sfTrue) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(w);
            exit(0);
        }
    }
    return;
}
