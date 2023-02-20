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
static void make_claus_sprite(cchara *element);
static void make_claus_box(cchara *element);
static void make_claus_stats(cchara *element);
static void make_claus_text(cchara *element, sfFont *m3font);

void make_claus(cchara **cc)
{
    cchara *element;
    element = malloc(sizeof(*element));
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    make_claus_sprite(element);
    make_claus_box(element);
    make_claus_stats(element);
    make_claus_text(element, m3font);
    make_hp(element);
    element->next = *cc;
    *cc = element;
    return;
}

static void make_claus_sprite(cchara *element)
{
    sfSprite *claus = sfSprite_create();
    sfTexture *T_claus =
    sfTexture_createFromFile("assets/battle/sprites/claus_portrait.png", NULL);
    sfVector2f scale = {5 , 5};
    sfVector2f pos = {0, 500};
    sfSprite_setTexture(claus, T_claus, sfFalse);
    sfSprite_setScale(claus, scale);
    sfSprite_setPosition(claus, pos);
    element->sprite = claus;
    element->pos = pos;
    return;
}

static void make_claus_box(cchara *element)
{
    sfSprite *box = sfSprite_create();
    sfTexture *T_box =
    sfTexture_createFromFile("assets/battle/sprites/claus_box.png", NULL);
    sfVector2f bscale = {5, 5};
    sfVector2f bpos = {0, 0};
    sfSprite_setTexture(box, T_box, sfFalse);
    sfSprite_setScale(box, bscale);
    sfSprite_setPosition(box, bpos);
    element->box = box;
    element->bpos = bpos;
    return;
}

static void make_claus_stats(cchara *element)
{
    element->name = "Claus";
    element->lvl = 2;
    element->hp = 84;
    element->attack = 7;
    element->exp = 99;
    element->max_tic = 6;
    element->tic = 0;
    sfSoundBuffer *buff =
    sfSoundBuffer_createFromFile("assets/battle/bgm/claus.wav");
    sfSound *s = sfSound_create();
    sfSound_setBuffer(s, buff);
    element->sound = s;
    return;
}

static void make_claus_text(cchara *element, sfFont *m3font)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "Claus attacks !");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 70);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    element->msg = txt;
}
