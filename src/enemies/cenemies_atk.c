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

void cenemies_atk(sfRenderWindow *window, clevel *cl)
{
    cenemies *tmp = cl->ce;
    while (tmp) {
        if (tmp->tic <= 0) {
            cl->info = tmp->msg;
            cl->cc->hp -= tmp->attack;
            sfRenderWindow_clear(window, sfRed);
            tmp->tic = tmp->max_tic;
            sfSound_play(cl->ouch);
        }
        tmp = tmp->next;
    }
    return;
}
