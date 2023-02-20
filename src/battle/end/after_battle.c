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
static void display_win(sfRenderWindow *window, clevel *cl,
sfTime time, sfClock *clock);
static void create_level_up_txt(clevel *cl);

static void display_win(sfRenderWindow *window, clevel *cl,
sfTime time, sfClock *clock)
{
    sfRenderWindow_display(window);
    sfRenderWindow_drawSprite(window, cl->back, NULL);
    display_chained_characters(window, cl);
    sfRenderWindow_drawSprite(window, cl->w, NULL);
    if (time.microseconds / 1000000.0 > 0.20) {
        update_background(cl);
        time = sfClock_restart(clock);
    if (cl->info_state == 0) {
        sfText_setColor(cl->info, sfColor_fromRGB(100, 100, 100) );
        cl->info_state = 1;
    } else {
        sfText_setColor(cl->info, sfBlack);
        cl->info_state = 0;
    }
    sfRenderWindow_drawText(window, cl->info, NULL);
    }
}

static void create_level_up_txt(clevel *cl)
{
    sfText *txt = sfText_create();
    sfText_setString(txt, "Your team gained some exp !");
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    sfVector2f t_pos = {150, 60};
    sfText_setFont(txt, m3font);
    sfText_setCharacterSize(txt, 70);
    sfText_setPosition(txt, t_pos);
    sfText_setColor(txt, sfBlack);
    cl->info = txt;
}

void after_battle(sfRenderWindow *window, clevel *cl,
sfClock *clock, sfTime time)
{
    cchara_gain_exp(cl);
    if (is_lvl_up(cl->cc) == 1) {
        level_up(cl);
        create_level_up_txt(cl);
        exp_win(window, cl, clock, time);
    }
    if (cl->next) {
        intro1(window);
        set_pos_characters(cl);
        return (prologue_window(window, cl->next, time));
    }
    sfEvent event;
    load_window(window, event, 1);
}

void exp_win(sfRenderWindow *window, clevel *cl, sfClock *clock, sfTime time)
{
    sfEvent e;

    sfMusic *m = sfMusic_createFromFile("assets/battle/end/bgm/levelup.ogg");
    sfMusic_play(m);
    float time_buffer = 0.00;
    while (time_buffer < 10.0) {
        close_window(window, e);
        time = sfClock_getElapsedTime(clock);
        time_buffer += time.microseconds / 1000000.0;
        display_win(window, cl, time, clock);
        sfRenderWindow_display(window);
    } sfMusic_destroy(m);
}
