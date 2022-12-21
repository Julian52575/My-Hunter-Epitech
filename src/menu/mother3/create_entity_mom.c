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

sfIntRect create_entity_mom(sfSprite *mom3)
{
    sfIntRect rect;
    rect.top = 34;
    rect.left = 243;
    rect.width = 466 - 244;
    rect.height = 89 - 34;
    sfSprite_setTextureRect(mom3, rect);
    sfTexture *t_title =
    sfTexture_createFromFile("assets/menu/sprites/menu.png", NULL);
    sfVector2f my_pos = {140, 80};
    sfVector2f scale = {7, 7};
    sfSprite_setScale(mom3, scale);
    sfSprite_setPosition(mom3, my_pos);
    sfSprite_setTexture(mom3, t_title, sfFalse);
    return rect;
}
