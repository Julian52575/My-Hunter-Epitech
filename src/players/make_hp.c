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
static void make_hp2(cchara *element);
static void make_hp3(cchara *element);

void make_hp(cchara *element)
{
    sfSprite *HP = sfSprite_create();
    sfTexture *T_HP =
    sfTexture_createFromFile("assets/battle/sprites/HP_slot.png", NULL);
    sfVector2f scale = {5, 5};
    sfVector2f pos = {element->bpos.x + 145, element->bpos.y + 220};
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 7;
    rect.height = 7;
    sfSprite_setTextureRect(HP, rect);
    sfSprite_setTexture(HP, T_HP, sfFalse);
    sfSprite_setScale(HP, scale);
    sfSprite_setPosition(HP, pos);
    element->HP1 = HP;
    element->rect_hp1 = rect;
    make_hp2(element);
}

void make_hp2(cchara *element)
{
    sfSprite *HP = sfSprite_create();
    sfTexture *T_HP =
    sfTexture_createFromFile("assets/battle/sprites/HP_slot.png", NULL);
    sfVector2f scale = {5, 5};
    sfVector2f pos = {element->bpos.x + 185, element->bpos.y + 220};
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 7;
    rect.height = 7;
    sfSprite_setTextureRect(HP, rect);
    sfSprite_setTexture(HP, T_HP, sfFalse);
    sfSprite_setScale(HP, scale);
    sfSprite_setPosition(HP, pos);
    element->HP2 = HP;
    element->rect_hp2 = rect;
    make_hp3(element);
}

void make_hp3(cchara *element)
{
    sfSprite *HP = sfSprite_create();
    sfTexture *T_HP =
    sfTexture_createFromFile("assets/battle/sprites/HP_slot.png", NULL);
    sfVector2f scale = {5, 5};
    sfVector2f pos = {element->bpos.x + 225, element->bpos.y + 220};
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 7;
    rect.height = 7;
    sfSprite_setTextureRect(HP, rect);
    sfSprite_setTexture(HP, T_HP, sfFalse);
    sfSprite_setScale(HP, scale);
    sfSprite_setPosition(HP, pos);
    element->HP3 = HP;
    element->rect_hp3 = rect;
}
