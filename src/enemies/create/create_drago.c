/*
** EPITECH PROJECT, 2022
** create dragoroom
** File description:
** this value of cenemies is now a ramblin' dragoroom
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
static void text_drago(cenemies *element, sfFont *m3font);
static void size_drago(cenemies *element, sfSprite *sp);
void stat_drago(cenemies *element);

void create_enemy_drago(cenemies **ce)
{
    sfSprite *sp = sfSprite_create();
    sfTexture *t_sp =
    sfTexture_createFromFile("assets/chapter1/sprites/drago.png", NULL);
    sfSprite_setTexture(sp, t_sp, sfFalse);
    cenemies *element;
    element = malloc(sizeof(*element));
    size_drago(element, sp);
    element->sprite = sp;
    stat_drago(element);
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    text_drago(element, m3font);
    element->next = *ce;
    *ce = element;
}

static void size_drago(cenemies *element, sfSprite *sp)
{
    sfVector2f my_scale = {5, 5};
    sfSprite_setScale(sp, my_scale);
    sfVector2f my_pos = {2000, 300};
    sfSprite_setPosition(sp, my_pos);
    element->pos = my_pos;
    return;
}

void stat_drago(cenemies *element)
{
    element->x_hitbox = 100 * 5;
    element->y_hitbox = 81 * 5;
    element->hp = 340;
    element->attack = 97;
    element->max_tic = 16;
    element->tic = 85;
    element->exp = 800;
    element->name = "Mecha Drago";
    element->pattern = 6;
    return;
}

static void text_drago(cenemies *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "Mecha drago attacks !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 80);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
