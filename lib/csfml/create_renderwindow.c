/*
** EPITECH PROJECT, 2022
** create
** File description:
** and render a window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>

sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y
, unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL));
}
