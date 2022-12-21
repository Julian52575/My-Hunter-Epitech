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
static int load_window_events(sfRenderWindow *window,
sfEvent event, int prologue);
static void between_load(sfRenderWindow *window, int a,
sfSprite *mom3, sfSprite *back);

static int load_window_events(sfRenderWindow *window,
sfEvent event, int prologue)
{
    if (sfRenderWindow_pollEvent(window, &event) == sfFalse)
        return 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        sfVector2i mouse = sfMouse_getPosition(window);
        return (button_load(mouse.x, mouse.y, prologue) );
    }
    if (event.key.code == sfKeyEscape)
        return -1;
    return 1;
}

static void between_load(sfRenderWindow *window, int a,
sfSprite *mom3, sfSprite *back)
{
    if (a == -1) {
        sfSprite_destroy(mom3);
        sfSprite_destroy(back);
        create_chapter1_window(window);
    }
    if (a == -2) {
        sfSprite_destroy(mom3);
        sfSprite_destroy(back);
        create_prologue_window(window);
    }
}

void load_window(sfRenderWindow *window, sfEvent event, int prologue)
{
    sfSprite *load = sfSprite_create();
    create_entity_load(load);
    sfSprite *black_background = sfSprite_create();
    create_black_sprite(black_background);
    ctext *ct;
    ct = NULL;
    create_text_load(&ct);
    sfMusic *music = sfMusic_createFromFile("assets/menu/bgm/save.wav");
    sfMusic_play(music);
    int a = 42;
    while (a > 0) {
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, black_background, NULL);
        sfRenderWindow_drawSprite(window, load, NULL);
        display_chained_text(window, ct);
        a = load_window_events(window, event, prologue);
    } sfMusic_destroy(music);
    between_load(window, a, load, black_background);
}
