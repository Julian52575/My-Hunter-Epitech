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

void level_up(clevel *cl)
{
    cchara *tmp = cl->cc;
    for (int n = 0; n < cl->cc_len ; n++) {
        if (tmp->exp > 100 + (10 * tmp->lvl)) {
            convert_exp_to_lvl(cl, tmp);
        }
        tmp = tmp->next;
    }
}
