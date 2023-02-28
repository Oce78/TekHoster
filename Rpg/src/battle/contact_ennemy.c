/*
** EPITECH PROJECT, 2022
** contact_ennemy.c
** File description:
** launcch a battle if you touch an ennemy
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

static void verif_pos(struct_object *object, struct_charachter foe)
{
    if (object->hero.position.x >= foe.position.x &&
    object->hero.position.x <= foe.position.x + foe.size_x) {
        if (object->hero.position.y >= foe.position.y &&
        object->hero.position.y <= foe.position.y + foe.size_y) {
            foe = init_battle(object, foe);
            object->current_ennemy = foe;
        } else if (object->hero.position.y + object->hero.rect.height >=
        foe.position.y && object->hero.position.y + object->hero.rect.height <=
        foe.position.y + foe.rect.height) {
            foe = init_battle(object, foe);
            object->current_ennemy = foe;
        } else if (object->hero.position.y + (object->hero.rect.height / 2) >=
        foe.position.y && object->hero.position.y +
        (object->hero.rect.height / 2) <= foe.position.y + foe.rect.height) {
            foe = init_battle(object, foe);
            object->current_ennemy = foe;
        }
    }
}

void verif_if_contact(struct_object *object)
{
    for (size_t x = 0; x < 4; x++)
        if (object->blob[x]->death == false)
            verif_pos(object, *object->blob[x]);
}
