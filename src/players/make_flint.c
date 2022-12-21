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
static void make_flint_sprite(cchara *element);
static void make_flint_box(cchara *element);
static void make_flint_stats(cchara *element);
static void make_flint_text(cchara *element, sfFont *m3font);

void make_flint(cchara **cc)
{
    cchara *element;
    element = malloc(sizeof(*element));
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    make_flint_sprite(element);
    make_flint_box(element);
    make_flint_stats(element);
    make_flint_text(element, m3font);
    make_hp(element);
    element->next = *cc;
    *cc = element;
}

static void make_flint_sprite(cchara *element)
{
    sfSprite *claus = sfSprite_create();
    sfTexture *T_claus =
    sfTexture_createFromFile("assets/battle/sprites/flint_portrait.png", NULL);
    sfVector2f scale = {5, 5};
    sfVector2f pos = {500, 0};
    sfSprite_setTexture(claus, T_claus, sfFalse);
    sfSprite_setScale(claus, scale);
    sfSprite_setPosition(claus, pos);
    element->sprite = claus;
    element->pos = pos;
}

static void make_flint_box(cchara *element)
{
    sfSprite *box = sfSprite_create();
    sfTexture *T_box =
    sfTexture_createFromFile("assets/battle/sprites/flint_box.png", NULL);
    sfVector2f bscale = {5, 5};
    sfVector2f bpos = {0, 700};
    sfSprite_setTexture(box, T_box, sfFalse);
    sfSprite_setScale(box, bscale);
    sfSprite_setPosition(box, bpos);
    element->box = box;
    element->bpos = bpos;
}

static void make_flint_stats(cchara *element)
{
    element->name = "Flint";
    element->lvl = 1;
    element->hp = 475;
    element->attack = 23;
    element->exp = 98;
    element->max_tic = 9;
    element->tic = 0;
    sfSoundBuffer *buff =
    sfSoundBuffer_createFromFile("assets/battle/bgm/flint.wav");
    sfSound *s = sfSound_create();
    sfSound_setBuffer(s, buff);
    element->sound = s;
    return;
}

static void make_flint_text(cchara *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "Flint attacks !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 70);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
