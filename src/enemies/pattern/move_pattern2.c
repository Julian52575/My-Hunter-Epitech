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

void move_pattern6(cenemies *ce)
{
    ce->pos.x -= 1;
    if (ce->pos.x <= 500.0) {
        ce->pattern = 7;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern7(cenemies *ce)
{
    ce->pos.y += 50;
    if (ce->pos.y >= 600) {
        ce->pattern = 8;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern8(cenemies *ce)
{
    ce->pos.y -= 40;
    if (ce->pos.y <= 300) {
        ce->pattern = 9;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern9(cenemies *ce)
{
    ce->pos.x -= 10;
    if (ce->pos.x <= -400) {
        ce->pos.x = 2100;
        ce->pattern = 10;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}

void move_pattern10(cenemies *ce)
{
    ce->pos.x -= 10;
    if (ce->pos.x <= 500) {
        ce->pattern = 7;
    }
    sfSprite_setPosition(ce->sprite, ce->pos);
}
