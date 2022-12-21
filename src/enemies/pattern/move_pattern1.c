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

void move_pattern1(cenemies *ce)
{
    ce->pos.x -= 6;
    if (ce->pos.x <= -100) {
        ce->pos.x = 1980 / 2 + 300;
        ce->pos.y = -100;
        ce->pattern = 2;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern2(cenemies *ce)
{
    ce->pos.y += 12;
    if (ce->pos.y >= 1180) {
        ce->pattern = 1;
        ce->pos.x = 2080;
        ce->pos.y = 421;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern3(cenemies *ce)
{
    ce->pos.x += 13;
    if (ce->pos.x > 1980 - 250 - (1980 * 0.16)) {
        ce->pattern = 4;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern4(cenemies *ce)
{
    ce->pos.x -= 17.125;
    ce->pos.y += 11;
    if (ce->pos.x < 870) {
        ce->pattern = 5;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern5(cenemies *ce)
{
    ce->pos.x -= 17.125;
    ce->pos.y -= 11;
    if (ce->pos.x < 316) {
        ce->pattern = 3;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}
