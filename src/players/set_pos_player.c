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
#include "my.h"
#include "my_csfml.h"
#include "hunter.h"
static void set_hp_pos_characters(clevel *cl);
static void set_hp_rect_characters(clevel *cl);

static void set_hp_pos_characters(clevel *cl)
{
    cl->cc->pos.x = cl->cc->bpos.x + 115;
    cl->cc->pos.y = cl->cc->bpos.y - 75;
    sfSprite_setPosition(cl->cc->sprite, cl->cc->pos);
    int a = cl->cc->bpos.x + 145;
    sfVector2f pos = {a, 920};
    sfSprite_setPosition(cl->cc->HP1, pos);
    a = cl->cc->bpos.x + 185;
    sfVector2f pos2 = {a, 920};
    sfSprite_setPosition(cl->cc->HP2, pos2);
    a = cl->cc->bpos.x + 225;
    sfVector2f pos3 = {a, 920};
    sfSprite_setPosition(cl->cc->HP3, pos3);
}

static void set_hp_rect_characters(clevel *cl)
{
    cl->cc->rect_hp1.left = 72 * get_1st_digit(cl->cc->hp);
    sfSprite_setTextureRect(cl->cc->HP1, cl->cc->rect_hp1);
    cl->cc->rect_hp2.left = 72 * get_2nd_digit(cl->cc->hp);
    sfSprite_setTextureRect(cl->cc->HP2, cl->cc->rect_hp2);
    cl->cc->rect_hp3.left = 72 * get_3rd_digit(cl->cc->hp);
    sfSprite_setTextureRect(cl->cc->HP3, cl->cc->rect_hp3);
}

void set_pos_characters(clevel *cl)
{
    cchara *tmp = cl->cc;
    for (int n = 0; n < cl->cc_len ; n++) {
        cl->cc->bpos.x = 500 + (500 * n);
        cl->cc->bpos.y = 855;
        sfSprite_setPosition(cl->cc->box, cl->cc->bpos);
        set_hp_pos_characters(cl);
        set_hp_rect_characters(cl);
        cl->cc = cl->cc->next;
    } cl->cc = tmp;
}
