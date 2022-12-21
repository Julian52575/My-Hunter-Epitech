/*
** EPITECH PROJECT, 2022
** reverse visible
** File description:
** the invisible becomes visible and vice versa
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


void reverse_visible(csprites *cs, ctext *ct)
{
    reverse_visible_sprites(cs);
    reverse_visible_text(ct);
}

void reverse_visible_sprites(csprites *cs)
{
    while (cs) {
        if (cs->hidden == 1) {
            cs->hidden = 0;
        }
        if (cs->hidden == 0) {
            cs->hidden = 1;
        }
        cs = cs->next;
    }
    return;
}

void reverse_visible_text(ctext *ct)
{
    while (ct) {
        if (ct->hidden == 1) {
            ct->hidden = 0;
        }
        if (ct->hidden == 0) {
            ct->hidden = 1;
        }
        ct = ct->next;
    }
    return;
}
