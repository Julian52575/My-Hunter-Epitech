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

int add_cchara_hp(clevel *cl)
{
    cchara *tmp = cl->cc;
    int all_hp = 0;
    for (int n = 0; n < cl->cc_len ; n++) {
        all_hp += tmp->hp;
        tmp = tmp->next;
    }
    return all_hp;
}
