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

int main_window_events(sfRenderWindow *window, sfEvent event)
{
    if (sfRenderWindow_pollEvent(window, &event) == sfFalse)
        return 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        sfVector2i mouse = sfMouse_getPosition(window);
        return (button(mouse.x, mouse.y) );
    }
    if (event.key.code == sfKeyEscape)
            sfRenderWindow_clear(window, sfRed);
    return 1;
}

void between_windows(sfRenderWindow *window, int a,
sfSprite *mom, sfSprite *back)
{
    sfEvent event;
    if (a == -1 && is_txt() == -1) {
        sfRenderWindow_clear(window, sfRed);
        sfSprite_destroy(mom);
        sfSprite_destroy(back);
        naming_window(window, event);
    } else if (a == -1 && is_txt() > -1) {
        sfSprite_destroy(mom);
        sfSprite_destroy(back);
        load_window(window, event, 0);
    }
    if (a == -2) {
        sfRenderWindow_clear(window, sfBlue);
    }
    main_window(window, event);
}

void main_window(sfRenderWindow *window, sfEvent event)
{
    sfSprite *mom3 = sfSprite_create();
    create_entity_mom(mom3);
    sfSprite *black_background = sfSprite_create();
    create_black_sprite(black_background);
    ctext *ct;
    ct = NULL;
    create_text_mom(&ct);
    sfMusic *music = sfMusic_createFromFile("assets/menu/bgm/letsbegin.wav");
    sfMusic_play(music);
    int a = 42;
    while (a > 0) {
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, black_background, NULL);
        sfRenderWindow_drawSprite(window, mom3, NULL);
        display_chained_text(window, ct);
        a = main_window_events(window, event);
    } sfMusic_destroy(music);
    between_windows(window, a, mom3, black_background);
}
