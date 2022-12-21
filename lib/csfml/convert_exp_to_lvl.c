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

void convert_exp_to_lvl(clevel *cl, cchara *tmp)
{
    for (int n = 0; n < cl->cc_len ; n++) {
        while (tmp->exp > 100) {
            tmp->exp -= 100;
            tmp->lvl += 1;
            tmp->attack = 4;
            tmp->hp += 3;
        }
        tmp = tmp->next;
    }
}
