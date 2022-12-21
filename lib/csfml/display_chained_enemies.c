/*
** EPITECH PROJECT, 2022
** display chained enemies
** File description:
** Display enemies if their hp > 0
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

void display_chained_enemies(sfRenderWindow *window, cenemies *ce)
{
    cenemies *tmp = ce;
    while (tmp) {
        if (tmp->hp > 0) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        }
        tmp = tmp->next;
    }
}
