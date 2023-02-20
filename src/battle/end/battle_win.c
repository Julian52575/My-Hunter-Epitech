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
static sfSprite *congratualion_youre_the_best_wow_sprite(void);
static void display_win(sfRenderWindow *window,
clevel *cl, sfSprite *you_win);

static sfSprite *congratualion_youre_the_best_wow_sprite(void)
{
    sfSprite *lol = sfSprite_create();
    sfTexture *t = sfTexture_createFromFile
    ("assets/battle/end/sprite/youwin.png", NULL);
    sfVector2f scale = {11, 11};
    sfVector2f pos = {420, 60};
    sfSprite_setTexture(lol, t, sfFalse);
    sfSprite_setPosition(lol, pos);
    sfSprite_setScale(lol, scale);
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 95;
    rect.height = 10;
    sfSprite_setTextureRect(lol, rect);
    return lol;
}

static void display_win(sfRenderWindow *window, clevel *cl, sfSprite *you_win)
{
    sfRenderWindow_drawSprite(window, cl->back, NULL);
    display_chained_characters(window, cl);
    sfRenderWindow_drawSprite(window, cl->w, NULL);
    sfRenderWindow_drawSprite(window, you_win, NULL);
}

void battle_win(sfRenderWindow *window, clevel *cl, sfTime time)
{
    sfEvent e;

    sfClock *clock = sfClock_create();
    sfClock_restart(clock);
    float time_buffer = 0.00;
    sfMusic *m = sfMusic_createFromFile("assets/battle/end/bgm/youwon.ogg");
    sfMusic_play(m);
    sfSprite *you_win = congratualion_youre_the_best_wow_sprite();
    while (time_buffer < 6.0) {
        close_window(window, e);
        time = sfClock_getElapsedTime(clock);
        display_win(window, cl, you_win);
        if (time.microseconds / 1000000.0 > 0.20) {
            update_background(cl);
            time_buffer += time.microseconds / 1000000.0;
            time = sfClock_restart(clock);
        }
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(m);
    sfSprite_destroy(you_win);
    after_battle(window, cl, clock, time);
}
