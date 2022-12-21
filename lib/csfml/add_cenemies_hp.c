/*
** EPITECH PROJECT, 2022
** add cenemies hp
** File description:
** add all the hp of cenemies
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

int add_cenemies_hp(cenemies *ce)
{
    cenemies *tmp = ce;
    int all_hp = 0;
    while (tmp) {
        if (tmp->hp >= 0) {
            all_hp += tmp->hp;
        }
        tmp = tmp->next;
    }
    return all_hp;
}
