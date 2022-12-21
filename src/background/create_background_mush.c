/*
** EPITECH PROJECT, 2022
** main window.c
** File description:
** the main window of an tragedy
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include "my_csfml.h"
#include "hunter.h"

sfIntRect create_background_mush(clevel *cl, sfSprite *backg)
{
    sfTexture *t_back =
    sfTexture_createFromFile
    ("assets/chapter4/background_mush.png", NULL);
    sfSprite_setTexture(backg, t_back, sfFalse);
    sfIntRect b_rect;
    b_rect.top = 0;
    b_rect.left = 0;
    b_rect.width = 255;
    b_rect.height = 255;
    cl->btype = 2;
    sfVector2f back_scale = {7.3, 4.0};
    sfSprite_setScale(backg, back_scale);
    sfSprite_setTextureRect(backg, b_rect);
    return b_rect;
}
