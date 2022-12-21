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

sfIntRect create_entity_naming(sfSprite *naming)
{
    sfIntRect rect;
    rect.top = 1;
    rect.left = 1;
    rect.width = 1980;
    rect.height = 1080;
    sfSprite_setTextureRect(naming, rect);
    sfTexture *t_title =
    sfTexture_createFromFile("assets/placeholder.png", NULL);
    sfVector2f my_pos = {1, 1};
    sfVector2f scale = {1, 1};
    sfSprite_setScale(naming, scale);
    sfSprite_setPosition(naming, my_pos);
    sfSprite_setTexture(naming, t_title, sfFalse);
    return rect;
}
