/*
** EPITECH PROJECT, 2022
** put_inventory.c
** File description:
** this function do can put an item on the inventory
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

#define TOTALE_CASE 27

void put_inventory(struct_inventory **inventory, struct_baguette *baguette)
{
    int a = 0;

    for (; inventory[a]->used != false; a++)
        if (a >= TOTALE_CASE)
            return;
    inventory[a]->inv_s = baguette->baguette_s;
    inventory[a]->baguette = baguette;
}

//faire un truc avec return
