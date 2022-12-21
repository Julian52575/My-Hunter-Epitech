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

// void display_chained_characters(sfRenderWindow *window, clevel *cl)
// { //NEW !!!!!!//
//     int n = 0;
//     cchara *tmp = cl->cc;
//     for (int i = 0; cl->cc && i < cl->cc_len; i++) {
//         cl->cc->bpos.x = 500 + (500 * n);
//         cl->cc->bpos.y = 855;
//         sfSprite_setPosition(cl->cc->box, cl->cc->bpos);
//         cl->cc->pos.x = cl->cc->bpos.x + 115;
//         cl->cc->pos.y = cl->cc->bpos.y - 75;
//         sfSprite_setPosition(cl->cc->sprite, cl->cc->pos);

//         sfRenderWindow_drawSprite(window, cl->cc->sprite, NULL);
//         sfRenderWindow_drawSprite(window, cl->cc->box, NULL);
//         cl->cc = cl->cc->next;
//         n++;
//     }
//     cl->cc = tmp;
// }

void display_chained_characters(sfRenderWindow *window, clevel *cl)
{
    int i = 0;
    cchara *tmp = cl->cc;
    while (i < cl->cc_len) {
        sfRenderWindow_drawSprite(window, cl->cc->sprite, NULL);
        sfRenderWindow_drawSprite(window, cl->cc->box, NULL);
        sfRenderWindow_drawSprite(window, cl->cc->HP1, NULL);
        sfRenderWindow_drawSprite(window, cl->cc->HP2, NULL);
        sfRenderWindow_drawSprite(window, cl->cc->HP3, NULL);
        cl->cc = cl->cc->next;
        i++;
    }
    cl->cc = tmp;
}
