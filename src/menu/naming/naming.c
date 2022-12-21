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

void go_back_to_title(sfRenderWindow *window,
sfSprite *naming, sfSprite *back)
{
    sfEvent event;
    sfSprite_destroy(naming);
    sfSprite_destroy(back);
    main_window(window, event);
}

int naming_window_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            exit(84);
        }
        if (event.key.code == sfKeyEscape)
            return -1;
    }
    return 1;
}

void naming_window(sfRenderWindow *window, sfEvent event)
{
    sfSprite *naming = sfSprite_create();
    create_entity_naming(naming);
    sfSprite *black_background = sfSprite_create();
    create_black_sprite(black_background);
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    ctext *ct;
    ct = NULL;
    create_text_naming(&ct, m3font);
    sfMusic *music = sfMusic_createFromFile("assets/menu/bgm/funnaming.wav");
    int a = 42;
    while (a > 0) {
        sfMusic_play(music);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, black_background, NULL);
        sfRenderWindow_drawSprite(window, naming, NULL);
        display_chained_text(window, ct);
        a = naming_window_events(window, event);
    } go_back_to_title(window, naming, black_background);
}
