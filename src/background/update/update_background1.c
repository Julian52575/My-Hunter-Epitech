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

sfIntRect update_background_ohsosnake(sfSprite *sprite, sfIntRect rect)
{
    if (rect.left >= 1585.0 && rect.top >= 270.0) {
        rect.top = 7.0;
        rect.left = 7.0;
    } else if (rect.left >= 1585.0 && rect.top == 7.0) {
        rect.top = 270.0;
        rect.left = 7.0;
    } else {
        rect.left = rect.left + 263.0;
    }
    sfSprite_setTextureRect(sprite, rect);
    return rect;
}

void update_background_mole(clevel *cl)
{
    sfIntRect rect = cl->brect;
    if (rect.left >= 775 && rect.top == 2) {
        rect.top = 260;
        rect.left = 1;
    } else if (rect.left >= 517 && rect.top == 260) {
        rect.top = 2;
        rect.left = 1;
    } else {
        rect.left += 258;
    }
    cl->brect = rect;
    sfSprite_setTextureRect(cl->back, cl->brect);
}

void update_background_mushroom(clevel *cl)
{
    sfIntRect rect = cl->brect;
    if (rect.left >= 261 && rect.top >= 783){
        rect.top = 0;
        rect.left = 0;
    }
    if (rect.left < 783) {
        rect.left += 261;
    } else if (rect.left == 783) {
        rect.left = 0;
        rect.top += 261;
    }
    cl->brect = rect;
    sfSprite_setTextureRect(cl->back, cl->brect);
}

void update_background_drago(clevel *cl)
{
    sfIntRect rect = cl->brect;
    if (rect.left == 783) {
        if (rect.top == 783) {
            rect.left = 0;
            rect.top = 0;
        } else {
            rect.top += 261;
            rect.left = 0;
        }
    } else {
        rect.left += 261;
    }
    cl->brect = rect;
    sfSprite_setTextureRect(cl->back, cl->brect);
}
