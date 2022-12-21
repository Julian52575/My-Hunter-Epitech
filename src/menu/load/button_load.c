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
static int button_load2(int x, int y);

static int button_load2(int x, int y)
{
    if (x >= 578 && x <= 1404) {
        if (y >= 530 && y <= 1404) {
            return -1;
        }
    }
    return 1;
}

int button_load(int x, int y, int prologue)
{
    if (x >= 578 && x <= 1404) {
        if (y >= 173 && y <= 427) {
            return -2;
        }
    }
    if (prologue == 1) {
        return button_load2(x, y);
    }
    return 1;
}
