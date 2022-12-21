/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** the begging of an tragedy
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

void update_gameboy(sfIntRect *rect)
{
    if (rect->top < 588) {
        rect->top += 49;
    }
}
