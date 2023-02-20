/*
** EPITECH PROJECT, 2022
** my hunter.h
** File description:
** my hunter piou piou canards
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
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>

void close_window(sfRenderWindow *w, sfEvent e);

sfIntRect create_entity_gameboy(sfSprite *gameboy);
void create_entity_nintendo(sfSprite *nintendo);
sfIntRect create_entity_mom(sfSprite *mom3);
sfIntRect create_entity_naming(sfSprite *naming);
sfIntRect create_entity_load(sfSprite *load);

void create_text_mom(ctext **ct);
void create_text_naming(ctext **ct, sfFont *m3font);
void create_text_load(ctext **ct);

void update_gameboy(sfIntRect *rect);

void gameboy_window(sfRenderWindow *window, sfClock *clock, sfTime time);
void nintendo_window(sfRenderWindow *window, sfClock *clock, sfTime time);

void main_window(sfRenderWindow *window, sfEvent event);
int main_window_events(sfRenderWindow *window, sfEvent event);
int button(int x, int y);
void between_windows(sfRenderWindow *window, int a,
sfSprite *mom, sfSprite *back);
void naming_window(sfRenderWindow *window, sfEvent event);
void load_window(sfRenderWindow *window, sfEvent event, int prologue);
int button_load(int x, int y, int prologue);
void go_back_to_title(sfRenderWindow *window,
sfSprite *naming, sfSprite *back);

void create_prologue_window(sfRenderWindow *window);
void create_chapter1_window(sfRenderWindow *window);

int update_intro(sfIntRect *rect);

struct chained_enemies {
    sfSprite *sprite;
    sfVector2f pos;
    int x_hitbox;
    int y_hitbox;
    char *name;
    int hp;
    int attack;
    int max_tic;
    int tic;
    int exp;
    int pattern;
    sfText *msg;
    struct chained_enemies *next;
};
typedef struct chained_enemies cenemies;

struct chained_characters {
    char *name;
    sfText *msg;
    sfSprite *sprite;
    sfVector2f pos;
    sfSprite *box;
    sfVector2f bpos;
    sfSprite *HP1;
    sfIntRect rect_hp1;
    sfSprite *HP2;
    sfIntRect rect_hp2;
    sfSprite *HP3;
    sfIntRect rect_hp3;
    int lvl;
    int hp;
    int attack;
    int exp;
    sfSound *sound;
    int max_tic;
    int tic;
    struct chained_characters *next;
};
typedef struct chained_characters cchara;

struct chained_level {
    sfSprite *back;
    sfIntRect brect;
    int btype;
    cchara *cc;
    int cc_len;
    cenemies *ce;
    sfMusic *music;
    sfFont *font;
    sfSprite *intro;
    sfIntRect rect_intro;
    sfSprite *w;
    sfText *info;
    int info_state;
    sfSound *ouch;
    struct chained_level *next;
};
typedef struct chained_level clevel;

int detect_colision_chained(sfRenderWindow *window, int x, int y, clevel *cl);

void create_clevel_prologue(clevel **cl);
void create_clevel_prologue2(clevel **cl);

void create_chapter1_window(sfRenderWindow *window);
void create_clevel_chapter1(clevel **cl);

void create_enemy_bush(cenemies **ce);
void create_enemy_mush(cenemies **ce);
void create_enemy_molecricket(cenemies **ce);
void create_enemy_drago(cenemies **ce);

sfIntRect create_background_mole(clevel *cl, sfSprite *backg);
sfIntRect create_background_mush(clevel *cl, sfSprite *backg);
sfIntRect create_background_drago(clevel *cl, sfSprite *backg);

void update_background(clevel *cl);

void update_background_mole(clevel *cl);
void update_background_mushroom(clevel *cl);
void update_background_drago(clevel *cl);

void prologue_window(sfRenderWindow *window, clevel *cl,
sfTime time);
void chapter1_window(sfRenderWindow *window, clevel *cl, sfTime Btime);

void move_enemies(cenemies *ce);

void move_pattern1(cenemies *ce);
void move_pattern2(cenemies *ce);
void move_pattern3(cenemies *ce);
void move_pattern4(cenemies *ce);
void move_pattern5(cenemies *ce);
void move_pattern6(cenemies *ce);
void move_pattern7(cenemies *ce);
void move_pattern8(cenemies *ce);
void move_pattern9(cenemies *ce);
void move_pattern10(cenemies *ce);
void move_pattern11(cenemies *ce);
void move_pattern12(cenemies *ce);
void move_pattern13(cenemies *ce);

void intro1(sfRenderWindow *window);
void intro2(sfRenderWindow *window);

int add_cenemies_hp(cenemies *ce);
int add_cchara_hp(clevel *cl);

void convert_exp_to_lvl(clevel *cl, cchara *tmp);

void display_chained_enemies(sfRenderWindow *window, cenemies *ce);
void display_chained_characters(sfRenderWindow *window, clevel *cl);

void make_hp(cchara *element);

void make_claus(cchara **cc);
void make_lucas(cchara **cc);
void make_flint(cchara **cc);

void reduce_tic(clevel *cl);

int doing_attacks(sfRenderWindow *window, clevel *cl);
void cchara_atk(sfRenderWindow *window, clevel *cl);
void cenemies_atk(sfRenderWindow *window, clevel *cl);
void killing_enemy(sfRenderWindow *window, cenemies *ce);

float time_matters(clevel *cl, sfClock *clock, float time_buffer);

void update_hp(clevel *cl);
void update_tic_pos(clevel *cl);

void battle_end(sfRenderWindow *window, clevel *cl, int a);
void after_battle(sfRenderWindow *window, clevel *cl,
sfClock *clock, sfTime time);
void battle_win(sfRenderWindow *window, clevel *cl, sfTime time);
void exp_win(sfRenderWindow *window, clevel *cl, sfClock *clock, sfTime time);
void battle_lose(sfRenderWindow *window, clevel *cl);

void cchara_gain_exp(clevel *cl);
int is_lvl_up(cchara *cc);
void level_up(clevel *cl);

void set_pos_characters(clevel *cl);
