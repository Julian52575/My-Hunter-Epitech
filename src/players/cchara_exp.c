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

void cchara_gain_exp(clevel *cl)
{
    cchara *tmp_cc = cl->cc;
    cenemies *tmp_ce = cl->ce;
    for (int n = 0; n < cl->cc_len ; n++) {
        while (tmp_ce) {
            tmp_cc->exp += tmp_ce->exp;
            tmp_ce = tmp_ce->next;
        }
        tmp_ce = cl->ce;
        tmp_cc = tmp_cc->next;
    }
}
