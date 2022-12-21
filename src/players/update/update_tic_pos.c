/*
** EPITECH PROJECT, 2022
** upadte tic pos
** File description:
** he hides under the box if he can't attack
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
static void update_tic_pos2(cchara *tmp);

static void update_tic_pos2(cchara *tmp)
{
    if (tmp->tic <= 0) {
        tmp->pos.y = tmp->bpos.y - 75;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
    } else {
        tmp->pos.y = tmp->bpos.y - 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
    }
}

void update_tic_pos(clevel *cl)
{
    cchara *tmp = cl->cc;
    for (int n = 0; n < cl->cc_len ; n++) {
        update_tic_pos2(tmp);
        tmp = tmp->next;
    }
}
