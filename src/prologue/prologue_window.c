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
static void display_stuff(sfRenderWindow *window, clevel *cl);

static void display_stuff(sfRenderWindow *window, clevel *cl)
{
    sfRenderWindow_display(window);
    sfRenderWindow_drawSprite(window, cl->back, NULL);
    display_chained_enemies(window, cl->ce);
    display_chained_characters(window, cl);
    sfRenderWindow_drawSprite(window, cl->w, NULL);
    if (cl->info_state == 0) {
        sfText_setColor(cl->info, sfColor_fromRGB(100, 100, 100) );
        cl->info_state = 1;
    } else {
        sfText_setColor(cl->info, sfBlack);
        cl->info_state = 0;
    }
    sfRenderWindow_drawText(window, cl->info, NULL);
}

void prologue_window(sfRenderWindow *window, clevel *cl, sfTime Btime)
{
    set_pos_characters(cl);
    sfMusic_play(cl->music);
    sfClock *clock = sfClock_create();
    float time_buffer = 0.00;
    int a = 0;
    while (a == 0) {
        display_stuff(window, cl);
        time_buffer = time_matters(cl, clock, time_buffer);
        a = doing_attacks(window, cl);
    }
    sfMusic_destroy(cl->music);
    battle_end(window, cl, a);
}
