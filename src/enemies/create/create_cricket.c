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
static void text_molecricket(cenemies *element, sfFont *m3font);
static void size_molecricket(cenemies *element, sfSprite *sp);
static void stat_molecricket(cenemies *element);

void create_enemy_molecricket(cenemies **ce)
{
    cenemies *element;
    element = malloc(sizeof(*element));
    sfSprite *sp = sfSprite_create();
    sfTexture *t_sp =
    sfTexture_createFromFile("assets/prologue/sprites/molecricket.png", NULL);
    sfSprite_setTexture(sp, t_sp, sfFalse);
    size_molecricket(element, sp);
    element->sprite = sp;
    stat_molecricket(element);
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    text_molecricket(element, m3font);
    element->next = *ce;
    *ce = element;
}

static void size_molecricket(cenemies *element, sfSprite *sp)
{
    sfVector2f my_scale = {4, 4};
    sfSprite_setScale(sp, my_scale);
    sfVector2f my_pos = {2100, 620};
    sfSprite_setPosition(sp, my_pos);
    element->pos = my_pos;
    return;
}

static void stat_molecricket(cenemies *element)
{
    element->x_hitbox = 35 * 4;
    element->y_hitbox = 25 * 4;
    element->hp = 5;
    element->attack = 4;
    element->max_tic = 30;
    element->tic = 20;
    element->exp = 12;
    element->name = "Mole cricket";
    element->pattern = 1;
    return;
}

static void text_molecricket(cenemies *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "The mole cricket attacks !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 80);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
