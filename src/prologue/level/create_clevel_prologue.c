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
static void create_sprites(clevel *element);
static void create_text(clevel *element);
static void change_ce_pos(cenemies *ce);

static void change_ce_pos(cenemies *ce)
{
    ce->pos.x += 500;
    ce->pos.y += 150;
}

void create_clevel_prologue(clevel **cl)
{
    cenemies *ce;
    ce = NULL;
    create_enemy_mush(&ce);
    create_enemy_mush(&ce);
    ce->tic = 7;
    change_ce_pos(ce);
    cchara *cc;
    cc = NULL;
    make_lucas(&cc);
    make_claus(&cc);
    cc->next->next = cc;
    clevel *element;
    element = malloc(sizeof(*element));
    create_sprites(element);
    create_text(element);
    element->cc = cc;
    element->cc_len = 2;
    element->ce = ce;
    element->info_state = 0;
    element->next = *cl;
    *cl = element;
}

static void create_sprites(clevel *element)
{
    sfSprite *backg = sfSprite_create();
    element->brect = create_background_mush(element, backg);
    element->back = backg;
    element->music =
    sfMusic_createFromFile("assets/chapter4/bgm/mambo.ogg");
    sfSprite *w = sfSprite_create();
    sfTexture *T_w =
    sfTexture_createFromFile("assets/battle/sprites/window.png", NULL);
    sfVector2f scale = {13.5 , 4.5};
    sfVector2f pos = {30, 0};
    sfSprite_setTexture(w, T_w, sfFalse);
    sfSprite_setScale(w, scale);
    sfSprite_setPosition(w, pos);
    element->w = w;
    sfSoundBuffer *buff =
    sfSoundBuffer_createFromFile("assets/battle/bgm/ouch.ogg");
    sfSound *s = sfSound_create();
    sfSound_setBuffer(s, buff);
    element->ouch = s;
}

static void create_text(clevel *element)
{
    sfFont *m3font = sfFont_createFromFile("assets/earthmomma.ttf");
    sfText *info = sfText_create();
    sfText_setString(info, "Be careful of enemies attacks!");
    sfVector2f game_pos = {150, 50};
    sfText_setFont(info, m3font);
    sfText_setCharacterSize(info, 60);
    sfText_setPosition(info, game_pos);
    sfText_setColor(info, sfBlack);
    element->info = info;
}
