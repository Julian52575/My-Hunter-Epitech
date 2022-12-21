/*
** EPITECH PROJECT, 2022
** cenemies
** File description:
** he dead so I removed it from my ce
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

void cenemies_death(cenemies *ce)
{
    while (ce) {
        if (ce->hp <= 0) {
            ce = ce->next;
        }
        ce = ce->next;
    }
}
