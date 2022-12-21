/*
** EPITECH PROJECT, 2022
** create bush
** File description:
** this value of cenemies is now a walking bushy
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
static void text_bush(cenemies *element, sfFont *m3font);
static void size_bush(cenemies *element, sfSprite *sp);
static void stat_bush(cenemies *element);

void create_enemy_bush(cenemies **ce)
{
    cenemies *element;
    element = malloc(sizeof(*element));
    sfSprite *sp = sfSprite_create();
    sfTexture *t_sp =
    sfTexture_createFromFile("assets/chapter1/bushy.png", NULL);
    sfSprite_setTexture(sp, t_sp, sfFalse);
    size_bush(element, sp);
    element->sprite = sp;
    stat_bush(element);
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    text_bush(element, m3font);
    element->next = *ce;
    *ce = element;
}

static void size_bush(cenemies *element, sfSprite *sp)
{
    sfVector2f my_scale = {4, 4};
    sfSprite_setScale(sp, my_scale);
    sfVector2f my_pos = {2000, 70};
    sfSprite_setPosition(sp, my_pos);
    element->pos = my_pos;
    return;
}

static void stat_bush(cenemies *element)
{
    element->x_hitbox = 30 * 4;
    element->y_hitbox = 38 * 4;
    element->hp = 1;
    element->attack = 0;
    element->max_tic = 15;
    element->tic = 7;
    element->exp = 20;
    element->name = "Walking Bushy";
    element->pattern = 2;
    return;
}

static void text_bush(cenemies *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "The Walking bush tries to attack !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 80);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
