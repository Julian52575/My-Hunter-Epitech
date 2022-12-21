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

void create_text_naming(ctext **ct, sfFont *m3font)
{
    ctext *element;
    element = malloc(sizeof(*element));
    sfText *new_game;
    new_game = sfText_create();
    sfText_setString(new_game,
    "PLACEHOLDER, press esc and verify the frog.txt file...");
    sfVector2f game_pos = {300, 550};
    sfText_setFont(new_game, m3font);
    sfText_setCharacterSize(new_game, 40);
    sfText_setPosition(new_game, game_pos);
    sfColor color = sfColor_fromRGB(255, 0, 0);
    sfText_setColor(new_game, color);
    element->entity = new_game;
    element->hidden = 0;
    element->next = *ct;
    *ct = element;
}
