/*
** EPITECH PROJECT, 2022
** verif_proxi.c
** File description:
** verif if the hero is near balkany
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void verif_proxi_balk_anny(struct_object *obj)
{
    if (obj->hero.position.x >= obj->balk_anny.position.x - 80
    && obj->hero.position.x <= obj->balk_anny.position.x + 80 +
    obj->balk_anny.size_x && obj->hero.position.y >=
    obj->balk_anny.position.y - 80 && obj->hero.position.y <=
    obj->hero.position.y + 80 + obj->balk_anny.size_y) {
        obj->dialogue_balk_anny.can_print = true;
        sfClock_restart(obj->dialogue_balk_anny.clock.clock);
    }
}

void verif_proxi_wife(struct_object *obj)
{
    if (obj->hero.position.x >= obj->wife.position.x - 80 &&
    obj->hero.position.x <= obj->wife.position.x + 80 + obj->wife.size_x &&
    obj->hero.position.y >= obj->wife.position.y - 80 &&
    obj->hero.position.y <= obj->wife.position.y + 80 + obj->wife.size_y) {
        obj->dialogue_wife.can_print = true;
        sfClock_restart(obj->dialogue_wife.clock.clock);
    }
}
