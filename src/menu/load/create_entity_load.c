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

sfIntRect create_entity_load(sfSprite *load)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 395;
    rect.height = 214;
    sfSprite_setTextureRect(load, rect);
    sfTexture *t_title =
    sfTexture_createFromFile("assets/load.png", NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {5, 5};
    sfSprite_setScale(load, scale);
    sfSprite_setPosition(load, my_pos);
    sfSprite_setTexture(load, t_title, sfFalse);
    return rect;
}
