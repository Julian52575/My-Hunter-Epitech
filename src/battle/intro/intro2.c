/*
** EPITECH PROJECT, 2022
** intro1
** File description:
** intro1
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
static sfIntRect create_intro2(sfSprite *intro1);

void intro2(sfRenderWindow *window)
{
    sfSprite *intro1 = sfSprite_create();
    sfIntRect rect = create_intro2(intro1);
    int a = -1;
    sfMusic *m = sfMusic_createFromFile
    ("assets/battle/bgm/intro/bigencounter.ogg");
    sfMusic_play(m);
    sfClock *c = sfClock_create();
    while (a < 0) {
        sfRenderWindow_display(window);
        sfTime t = sfClock_getElapsedTime(c);
        if (t.microseconds / 1000000.0 > 0.1 ) {
            sfSprite_setTextureRect(intro1, rect);
            sfRenderWindow_drawSprite(window, intro1, NULL);
            a = update_intro(&rect);
            t = sfClock_restart(c);
        }
    }
}

int update_intro2(sfIntRect *rect)
{
    if (rect->left == 1983) {
        rect->top += 165;
        rect->left = 7;
        return -1;
    }
    rect->left += 247;
    return -1;
}

static sfIntRect create_intro2(sfSprite *intro1)
{
    sfIntRect rect;
    rect.top = 5;
    rect.left = 7;
    rect.height = 159;
    rect.width = 239;
    sfTexture *Tintro1 = sfTexture_createFromFile
    ("assets/battle/sprites/intro/intro2.png", NULL);
    sfSprite_setTexture(intro1, Tintro1, sfFalse);
    sfSprite_setTextureRect(intro1, rect);
    sfVector2f scale = {8, 7};
    sfSprite_setScale(intro1, scale);
    return rect;
}
