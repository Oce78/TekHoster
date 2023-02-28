/*
** EPITECH PROJECT, 2022
** start_battle.c
** File description:
** start the battle and go until one die
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

void put_text_in_battle(struct_object *object, struct_charachter foe);

static int end_battle(struct_object *obj, struct_charachter foe)
{
    sfVector2f size = {1.0, 1.0};

    if (foe.pv <= 0 || obj->stat->pv <= 0) {
        if (foe.pv <= 0) {
            destroy_battle(obj);
            obj->stat->pv = obj->stat->health * 2;
            sfMusic_play(obj->music.music);
            obj->hero.position = obj->hero.recup;
            sfSprite_setPosition(obj->hero.sprite, obj->hero.position);
            sfSprite_setScale(obj->hero.sprite, size);
            obj->battle.battle_beg = false;
            obj->stat->exp += 50;
            if (foe.x == -1) {
                obj->bag_in_invent = true;
                obj->balk_anny.death = true;
            } else
                obj->blob[foe.x]->death = true;
        } else
            create_over(obj);
        if (obj->stat->exp >= 100) {
            obj->stat->lvl += 1;
            obj->stat->nbr_of_point += 1;
            obj->stat->exp -= 100;
        }
        return 1;
    }
    return 0;
}

void start_battle(struct_object *obj, struct_charachter foe)
{
    if (end_battle(obj, foe) == 1)
        return;
    put_text_in_battle(obj, foe);
}
