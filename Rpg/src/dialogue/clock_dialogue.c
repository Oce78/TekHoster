/*
** EPITECH PROJECT, 2022
** clock_dialogue.c
** File description:
** create and use the clock for the dialogue
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void create_clock_dialogue(struct_object *obj)
{
    obj->dialogue_wife.clock.clock = sfClock_create();
    obj->dialogue_balk_anny.clock.clock = sfClock_create();
}

void clock_dialogue_wife(struct_object *obj)
{
    obj->dialogue_wife.clock.time =
    sfClock_getElapsedTime(obj->dialogue_wife.clock.clock);
    obj->dialogue_wife.clock.seconds =
    obj->dialogue_wife.clock.time.microseconds / 1000000.0f;
    if (obj->dialogue_wife.clock.seconds > 5) {
        obj->dialogue_wife.can_print = false;
    }
    if (obj->dialogue_wife.clock.seconds > 5 && obj->bag_in_invent == true)
        obj->play = 0;
}

void clock_dialogue_balk_anny(struct_object *obj)
{
    obj->dialogue_balk_anny.clock.time =
    sfClock_getElapsedTime(obj->dialogue_balk_anny.clock.clock);
    obj->dialogue_balk_anny.clock.seconds =
    obj->dialogue_balk_anny.clock.time.microseconds / 1000000.0f;
    if (obj->dialogue_balk_anny.clock.seconds > 5) {
        obj->dialogue_balk_anny.can_print = false;
        init_battle(obj, obj->balk_anny);
        obj->current_ennemy = obj->balk_anny;
    }
}
