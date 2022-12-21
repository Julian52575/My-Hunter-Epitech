/*
** EPITECH PROJECT, 2022
** create mushroom
** File description:
** this value of cenemies is now a ramblin' mushroom
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
static void text_mush(cenemies *element, sfFont *m3font);
static void size_mush(cenemies *element, sfSprite *sp);
void stat_mush(cenemies *element);

void create_enemy_mush(cenemies **ce)
{
    sfSprite *sp = sfSprite_create();
    sfTexture *t_sp =
    sfTexture_createFromFile("assets/chapter4/mushroom.png", NULL);
    sfSprite_setTexture(sp, t_sp, sfFalse);
    cenemies *element;
    element = malloc(sizeof(*element));
    size_mush(element, sp);
    element->sprite = sp;
    stat_mush(element);
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    text_mush(element, m3font);
    element->next = *ce;
    *ce = element;
}

static void size_mush(cenemies *element, sfSprite *sp)
{
    sfVector2f my_scale = {4, 4};
    sfSprite_setScale(sp, my_scale);
    sfVector2f my_pos = {1980 * 0.16, 1080 * 0.33 - 115};
    sfSprite_setPosition(sp, my_pos);
    element->pos = my_pos;
    return;
}

void stat_mush(cenemies *element)
{
    element->x_hitbox = 28 * 4;
    element->y_hitbox = 28 * 4;
    element->hp = 10;
    element->attack = 2;
    element->max_tic = 6;
    element->tic = 5;
    element->exp = 8;
    element->name = "Ramblin' Mushroom";
    element->pattern = 3;
    return;
}

static void text_mush(cenemies *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "Ramblin Mushroom attacks !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 80);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
