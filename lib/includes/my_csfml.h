/*
** EPITECH PROJECT, 2022
** my csfml.h
** File description:
** all the prototypes (and structs ?) for my csfml projects
*/
#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>

struct chained_sprites {
    sfSprite *entity;
    sfIntRect rect;
    int hidden;
    char name;
    struct chained_sprites *next;
};
typedef struct chained_sprites csprites;

struct chained_text {
    sfText *entity;
    int hidden;
    struct chained_text *next;
};
typedef struct chained_text ctext;

struct chained_menu {
    sfSprite *entity;
    sfIntRect rect;
    sfMusic *music;
    csprites *cs;
    ctext *ct;
    char name;
    struct chained_menu *next;
};
typedef struct chained_menu cmenu;

sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y
, unsigned int bpp, char *title);

int display_chained_text(sfRenderWindow *window, ctext *ct);
int display_chained_sprites(sfRenderWindow *window, csprites *cs);

void create_blank_sprite(sfSprite *blank);
void create_black_sprite(sfSprite *blank);

int is_txt(void);

void reverse_visible(csprites *cs, ctext *ct);
void reverse_visible_sprites(csprites *cs);
void reverse_visible_text(ctext *ct);

int destroy_chained_sprites(sfRenderWindow *window, csprites *cs);
