/*
** EPITECH PROJECT, 2022
** display chained
** File description:
** functions to display all the chained lists I use
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

int display_chained_text(sfRenderWindow *window, ctext *ct)
{
    int n = 0;
    while (ct) {
        if (ct->hidden == 0) {
            sfRenderWindow_drawText(window, ct->entity, NULL);
        }
        ct = ct->next;
        ++n;
    }
    return n;
}

int display_chained_sprites(sfRenderWindow *window, csprites *cs)
{
    int n = 0;
    while (cs) {
        if (cs->hidden == 0) {
            sfRenderWindow_drawSprite(window, cs->entity, NULL);
        }
        cs = cs->next;
        n++;
    }
    return n;
}

int destroy_chained_sprites(sfRenderWindow *window, csprites *cs)
{
    int n = 0;
    while (cs) {
        if (cs->hidden == 0) {
            sfSprite_destroy(cs->entity);
        }
        cs = cs->next;
        n++;
    }
    return n;
}
