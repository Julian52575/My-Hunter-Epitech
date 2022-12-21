/*
** EPITECH PROJECT, 2022
** upadte hp
** File description:
** update the hp of a charcter using the M3 slot
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
static void update_hp3(cchara *tmp);
static void update_hp3(cchara *tmp);
static void update_hp2(cchara *tmp);

static void update_hp4(cchara *tmp)
{
    if (tmp->rect_hp3.left == 0 &&
    tmp->rect_hp3.left != 72 * get_3rd_digit(tmp->hp)) {
        tmp->rect_hp3.left = 711;
    } else if (tmp->rect_hp3.left != 72 * get_3rd_digit(tmp->hp)) {
            tmp->rect_hp3.left -= 9;
    }
    sfSprite_setTextureRect(tmp->HP3, tmp->rect_hp3);
}

static void update_hp3(cchara *tmp)
{
    if (tmp->rect_hp2.left == 0 &&
    tmp->rect_hp2.left != 72 * get_2nd_digit(tmp->hp)) {
        tmp->rect_hp2.left = 711;
    } else if (tmp->rect_hp2.left != 72 * get_2nd_digit(tmp->hp)) {
            tmp->rect_hp2.left -= 9;
    }
    sfSprite_setTextureRect(tmp->HP2, tmp->rect_hp2);
    update_hp4(tmp);
}

static void update_hp2(cchara *tmp)
{
    if (tmp->rect_hp1.left == 0 &&
    tmp->rect_hp1.left != 72 * get_1st_digit(tmp->hp)) {
        tmp->rect_hp1.left = 711;
    } else if (tmp->rect_hp1.left != 72 * get_1st_digit(tmp->hp)) {
            tmp->rect_hp1.left -= 9;
    }
    sfSprite_setTextureRect(tmp->HP1, tmp->rect_hp1);
    update_hp3(tmp);
}

void update_hp(clevel *cl)
{
    cchara *tmp = cl->cc;
    for (int n = 0; n < cl->cc_len ; n++) {
        if (tmp->hp > 0) {
            update_hp2(tmp);
        } else {
            tmp->rect_hp1.left = 0;
            tmp->rect_hp2.left = 0;
            tmp->rect_hp3.left = 0;
            sfSprite_setTextureRect(tmp->HP1, tmp->rect_hp1);
            sfSprite_setTextureRect(tmp->HP2, tmp->rect_hp2);
            sfSprite_setTextureRect(tmp->HP3, tmp->rect_hp3);
        }
        tmp = tmp->next;
    }
}
