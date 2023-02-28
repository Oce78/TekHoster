/*
** EPITECH PROJECT, 2022
** print_inventory.c
** File description:
** print our inventory
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

#define TOTALE_CASE 27

void print_inventory(struct_object *object, sfRenderWindow *window)
{
    for (int a = 0; a < TOTALE_CASE; a++)
        if (object->inventory[a]->used)
            sfRenderWindow_drawSprite(window, object->inventory[a]->inv_s,
            NULL);
}
