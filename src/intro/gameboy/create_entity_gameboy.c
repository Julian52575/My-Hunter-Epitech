/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** the begging of an tragedy
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

sfIntRect create_entity_gameboy(sfSprite *gameboy)
{
    sfIntRect rect;
    rect.top = 1;
    rect.left = 1;
    rect.width = 172;
    rect.height = 46;
    sfSprite_setTextureRect(gameboy, rect);
    sfTexture *t_title =
    sfTexture_createFromFile("assets/menu/sprites/gameboy.png", NULL);
    sfVector2f my_pos = {162 , 250};
    sfVector2f scale = {9, 9};
    sfSprite_setScale(gameboy, scale);
    sfSprite_setPosition(gameboy, my_pos);
    sfSprite_setTexture(gameboy, t_title, sfFalse);
    return rect;
}

void create_entity_nintendo(sfSprite *nintendo)
{
    sfIntRect rect;
    rect.top = 1;
    rect.left = 1;
    rect.width = 300;
    rect.height = 46;
    sfSprite_setTextureRect(nintendo, rect);
    sfTexture *t_title =
    sfTexture_createFromFile("assets/menu/sprites/nintendo.png", NULL);
    sfVector2f my_pos = {85, 340};
    sfVector2f scale = {7, 7};
    sfSprite_setScale(nintendo, scale);
    sfSprite_setPosition(nintendo, my_pos);
    sfSprite_setTexture(nintendo, t_title, sfFalse);
    return;
}
