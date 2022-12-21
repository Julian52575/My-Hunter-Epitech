/*
** EPITECH PROJECT, 2022
** move enemies
** File description:
** pos.x += 42
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

void move_enemies(cenemies *ce)
{
    void (* ptr[20]) (cenemies *ce);
    ptr[1] = &move_pattern1;
    ptr[2] = &move_pattern2;
    ptr[3] = &move_pattern3;
    ptr[4] = &move_pattern4;
    ptr[5] = &move_pattern5;
    ptr[6] = &move_pattern6;
    ptr[7] = &move_pattern7;
    ptr[8] = &move_pattern8;
    ptr[9] = &move_pattern9;
    ptr[10] = &move_pattern10;
    while (ce) {
        (* ptr[ce->pattern])(ce);
        ce = ce->next;
    }
}
