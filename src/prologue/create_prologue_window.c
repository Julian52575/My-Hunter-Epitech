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

// void set_pos_characters(clevel *cl)
// {
//     cchara *tmp = cl->cc;
//     for (int n = 0; n <= cl->cc_len ; n++) {
//         cl->cc->bpos.x = 500 + (500 * n);
//         cl->cc->bpos.y = 855;
//         sfSprite_setPosition(cl->cc->box, cl->cc->bpos);
//         cl->cc->pos.x = cl->cc->bpos.x + 115;
//         cl->cc->pos.y = cl->cc->bpos.y - 75;
//         sfSprite_setPosition(cl->cc->sprite, cl->cc->pos);
//         int a = cl->cc->bpos.x + 145;
//         sfVector2f pos = {a, 920};
//         sfSprite_setPosition(cl->cc->HP1, pos);
//         a = cl->cc->bpos.x + 185;
//         sfVector2f pos2 = {a, 920};
//         sfSprite_setPosition(cl->cc->HP2, pos2);
//         a = cl->cc->bpos.x + 225;
//         sfVector2f pos3 = {a, 920};
//         sfSprite_setPosition(cl->cc->HP3, pos3);
//         cl->cc = cl->cc->next;
//     } cl->cc = tmp;
// }

void create_prologue_window(sfRenderWindow *window)
{
    clevel *cl;
    cl = NULL;
    create_clevel_prologue(&cl);
    create_clevel_prologue2(&cl);
    sfTime time;
    set_pos_characters(cl);
    intro1(window);
    prologue_window(window, cl, time);
}
