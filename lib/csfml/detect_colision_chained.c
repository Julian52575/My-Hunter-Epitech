/*
** EPITECH PROJECT, 2022
** detect colision chained
** File description:
** is my mouse touching of the enemies ?
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
static int detect_colision_chained2(int x, int y, cenemies *ce);

int detect_colision_chained(sfRenderWindow *window, int x, int y, clevel *cl)
{
    cenemies *tmp = cl->ce;
    while (tmp) {
        if (detect_colision_chained2(x, y, tmp) == 1) {
            cl->cc = cl->cc->next;
            sfSound_play(cl->cc->sound);
            cl->info = cl->cc->msg;
            tmp->hp -= cl->cc->attack;
            killing_enemy(window, tmp);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

static int detect_colision_chained2(int x, int y, cenemies *ce)
{
    if (x >= ce->pos.x && x <= ce->pos.x + ce->x_hitbox) {
        if (y >= ce->pos.y && y <= ce->pos.y + ce->y_hitbox) {
            return 1;
        }
    }
    return -1;
}
