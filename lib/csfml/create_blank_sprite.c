/*
** EPITECH PROJECT, 2022
** create
** File description:
** blank sprite
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

void create_blank_sprite(sfSprite *blank)
{
    sfIntRect rect;
    rect.top = 1;
    rect.left = 1;
    rect.width = 1;
    rect.height = 1;
    sfSprite_setTextureRect(blank, rect);
    sfTexture *t_blank = sfTexture_createFromFile
    ("assets/menu/sprites/white.png", NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {1920, 1080};
    sfSprite_setScale(blank, scale);
    sfSprite_setPosition(blank, my_pos);
    sfSprite_setTexture(blank, t_blank, sfFalse);
}

void create_black_sprite(sfSprite *blank)
{
    sfIntRect rect;
    rect.top = 1;
    rect.left = 1;
    rect.width = 1;
    rect.height = 1;
    sfSprite_setTextureRect(blank, rect);
    sfTexture *t_blank = sfTexture_createFromFile
    ("assets/menu/sprites/black.png", NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {1920, 1080};
    sfSprite_setScale(blank, scale);
    sfSprite_setPosition(blank, my_pos);
    sfSprite_setTexture(blank, t_blank, sfFalse);
}
