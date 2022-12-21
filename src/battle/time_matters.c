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
#include "my.h"
#include "my_csfml.h"
#include "hunter.h"

float time_matters(clevel *cl, sfClock *clock, float time_buffer)
{
    sfTime Btime = sfClock_getElapsedTime(clock);
    time_buffer += Btime.microseconds / 1000000.0;
    if (Btime.microseconds / 1000000.0 > 0.01) {
        update_hp(cl);
        move_enemies(cl->ce);
    }
    if (Btime.microseconds / 1000000.0 > 0.15) {
        update_background(cl);
        Btime = sfClock_restart(clock);
    }
    if (time_buffer > 1.50) {
        reduce_tic(cl);
        update_tic_pos(cl);
        time_buffer = 0.00;
    }
    return time_buffer;
}
