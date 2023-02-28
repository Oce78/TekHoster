/*
** EPITECH PROJECT, 2022
** clock_battle.c
** File description:
** create the clock for the turn by turn
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

void create_clock_attack(struct_object *object)
{
    object->clock_attack.clock = sfClock_create();
}

void clock_attack(struct_object *object)
{
    object->clock_attack.time =
    sfClock_getElapsedTime(object->clock_attack.clock);
    object->clock_attack.seconds =
    object->clock_attack.time.microseconds / 1000000.0f;
    if (object->clock_attack.seconds > 2.5) {
        object->stat->pv -= rand() % 3;
        object->battle.can_attack = true;
        sfClock_restart(object->clock_attack.clock);
    }
}
