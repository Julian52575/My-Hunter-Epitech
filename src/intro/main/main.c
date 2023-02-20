/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** the begging of an tragedy
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
static void help(int ac);

void nintendo_window(sfRenderWindow *window, sfClock *clock, sfTime time)
{
    time = sfClock_restart(clock);
    time = sfClock_getElapsedTime(clock);
    sfSprite *black_background = sfSprite_create();
    create_black_sprite(black_background);
    sfSprite *nintendo = sfSprite_create();
    create_entity_nintendo(nintendo);
    sfMusic *M = sfMusic_createFromFile("assets/menu/bgm/gameboy.wav");
    sfMusic_play(M);
    while (time.microseconds / 1000000.0 <= 3) {
        time = sfClock_getElapsedTime(clock);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, black_background, NULL);
        sfRenderWindow_drawSprite(window, nintendo, NULL);
    } sfSprite_destroy(nintendo);
    sfSprite_destroy(black_background);
    sfEvent event;
    main_window(window, event);
}

void gameboy_window(sfRenderWindow *window, sfClock *clock, sfTime time)
{
    sfSprite *blank_background = sfSprite_create();
    create_blank_sprite(blank_background);

    sfSprite *gameboy = sfSprite_create();
    sfIntRect rect = create_entity_gameboy(gameboy);
    sfMusic *M = sfMusic_createFromFile("assets/menu/bgm/gameboy.wav");
    sfMusic_play(M);
    while (time.microseconds / 1000000.0 < 3) {
        time = sfClock_getElapsedTime(clock);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, blank_background, NULL);
        sfRenderWindow_drawSprite(window, gameboy, NULL);
        if (time.microseconds / 1000000.0 > 1.5) {
            update_gameboy(&rect);
            sfSprite_setTextureRect(gameboy, rect);
        }
    } sfSprite_destroy(gameboy);
    sfSprite_destroy(blank_background);
    nintendo_window(window, clock, time);
}

static void help(int ac)
{
    my_putstr("\tThis is my M0THER 3 inspired shooter game\n");
    my_putstr("It contains an HP system");
    my_putstr(", which means you have to hit ennemies multiple times, and multiple characters, just like the original game !!!\n");
    my_putstr("Feel free to look inside my code ! I used all the basics CSFML function and a TON of liked list (don't copy and paste if you want a better grade than -42)\n");
    my_putstr("Keep in mind this is a early project, so nothing is really optimized, but it should still be a nice showcase of what is doable in CSFML\n");
    return;
}

int main(int ac, char **av)
{
    if (ac > 1)
        if (av[1][0] == '-')
            help(ac);
    sfClock *clock = sfClock_create();
    sfTime time;
    time = sfClock_restart(clock);
    sfVideoMode video_mode = {1820, 1080, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(video_mode, "M0ther 3", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    gameboy_window(window, clock, time);
    return 0;
}
