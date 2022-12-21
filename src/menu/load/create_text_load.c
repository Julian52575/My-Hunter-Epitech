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

void create_text_load(ctext **ct)
{
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    ctext *element;
    element = malloc(sizeof(*element));
    sfText *prologue;
    prologue = sfText_create();
    sfText_setString(prologue, "Select a save file !");
    sfVector2f game_pos = {1080 / 2 , 10};
    sfText_setFont(prologue, m3font);
    sfText_setCharacterSize(prologue, 80);
    sfText_setPosition(prologue, game_pos);
    element->entity = prologue;
    element->hidden = 0;
    element->next = *ct;
    *ct = element;
}
