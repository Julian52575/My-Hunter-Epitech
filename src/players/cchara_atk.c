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
static int cchara_atk2(sfRenderWindow *window, clevel *cl);

void cchara_atk(sfRenderWindow *window, clevel *cl)
{
    if (cl->cc->tic <= 0)
        cchara_atk2(window, cl);
}

static int cchara_atk2(sfRenderWindow *window, clevel *cl)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        sfVector2i mouse = sfMouse_getPosition(window);
        if (detect_colision_chained(window, mouse.x, mouse.y, cl) == 1) {
            cl->cc->tic = cl->cc->max_tic;
            return 1;
        }
    }
    return 0;
}
