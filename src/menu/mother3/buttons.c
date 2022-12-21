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

int button(int x, int y)
{
    if (x >= 795 && x <= 1035) {
        if (y >= 550 && y <= 595) {
            return -1;
        }
    }
    if (x >= 805 && x <= 965) {
        if (y >= 640 && y <= 685) {
            return -2;
        }
    }
    return 1;
}
