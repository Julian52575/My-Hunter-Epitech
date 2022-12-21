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
static void create_text_mom2(ctext **ct, sfFont *m3font, sfColor color);
void create_text_mom3(ctext **ct, sfFont *m3font);

void create_text_mom(ctext **ct)
{
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    sfColor color = sfColor_fromRGB(200, 180, 190);
    ctext *element;
    element = malloc(sizeof(*element));
    int isTxt = is_txt();
    sfText *new_game;
    new_game = sfText_create();
    sfText_setString(new_game, "Continue");
    if (isTxt == -1)
        sfText_setString(new_game, "New game");
    sfVector2f game_pos = {800, 550};
    sfText_setFont(new_game, m3font);
    sfText_setCharacterSize(new_game, 40);
    sfText_setPosition(new_game, game_pos);
    sfText_setColor(new_game, color);
    element->entity = new_game;
    element->hidden = 0;
    element->next = *ct;
    *ct = element;
    create_text_mom2(ct, m3font, color);
}

static void create_text_mom2(ctext **ct, sfFont *m3font, sfColor color)
{
    ctext *element;
    element = malloc(sizeof(*element));
    sfText *option;
    option = sfText_create();
    sfText_setString(option, "Options");
    sfText_setFont(option, m3font);
    sfVector2f opt_pos = {802, 640};
    sfText_setPosition(option, opt_pos);
    sfText_setCharacterSize(option, 40);
    sfText_setColor(option, color);
    element->entity = option;
    element->hidden = 0;
    element->next = *ct;
    *ct = element;
    create_text_mom3(ct, m3font);
}

void create_text_mom3(ctext **ct, sfFont *m3font)
{
    ctext *element;
    element = malloc(sizeof(*element));
    sfText *copyrights;
    copyrights = sfText_create();
    sfText_setString(copyrights, "c Julian 2022 Epitech Project");
    sfText_setFont(copyrights, m3font);
    sfVector2f cpy_pos = {600, 930};
    sfText_setPosition(copyrights, cpy_pos);
    sfText_setCharacterSize(copyrights, 40);
    sfColor color = sfColor_fromRGB(160, 160, 160);
    sfText_setColor(copyrights, color);
    element->entity = copyrights;
    element->hidden = 0;
    element->next = *ct;
    *ct = element;
}
