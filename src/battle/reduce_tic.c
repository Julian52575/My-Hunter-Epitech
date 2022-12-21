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

void reduce_tic(clevel *cl)
{
    cenemies *tmp = cl->ce;
    while (tmp) {
        if (tmp->hp > 0) {
            tmp->tic -= 1;
        }
        tmp = tmp->next;
    }
    cchara *tmp2 = cl->cc;
    for (int n = 0; n < cl->cc_len ; n++) {
        if (tmp2->hp > 0) {
            tmp2->tic -= 1;
        }
        tmp2 = tmp2->next;
    }
}
