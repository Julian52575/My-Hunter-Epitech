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

int doing_attacks(sfRenderWindow *window, clevel *cl)
{
    cenemies_atk(window, cl);
    cchara_atk(window, cl);
    if (add_cenemies_hp(cl->ce) <= 0) {
        return 1;
    }
    if (add_cchara_hp(cl) <= 0) {
        return -1;
    }
    return 0;
}
