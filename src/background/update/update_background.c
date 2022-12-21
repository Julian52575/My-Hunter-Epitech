/*
** EPITECH PROJECT, 2022
** create bush
** File description:
** this value of cenemies is now a walking bushy
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

void update_background(clevel *cl)
{
    void (* ptr[20]) (clevel *cl);
    ptr[1] = &update_background_mole;
    ptr[2] = &update_background_mushroom;
    ptr[3] = &update_background_mushroom;
    (* ptr[cl->btype])(cl);
}
