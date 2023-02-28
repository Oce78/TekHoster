/*
** EPITECH PROJECT, 2022
** button_battle.c
** File description:
** create and use the button
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

static struct_charachter which_button_click(struct_object *obj,
sfVector2i mouse_pos, struct_charachter foe)
{
    if (mouse_pos.x <= 762) {
        foe.pv -= obj->stat->strenght;
        obj->battle.can_attack = false;
    } else if (mouse_pos.x >= 1048) {
        foe.pv -= obj->stat->wisdom;
        obj->battle.can_attack = false;
    } else if (mouse_pos.x >= 845 && mouse_pos.x <= 1000) {
        foe.pv -= obj->stat->dext;
        obj->battle.can_attack = false;
    }
    if (obj->battle.can_attack == false)
        sfClock_restart(obj->clock_attack.clock);
    return foe;
}

struct_charachter create_button_battle(struct_object *obj,
struct_charachter foe)
{
    sfVector2i mouse_pos;

    if (obj->event.event.type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPosition((const sfWindow *)obj->window.window);
        if (mouse_pos.y >= 950 && mouse_pos.y <= 1000 && mouse_pos.x >= 620 &&
        mouse_pos.x <= 1295 && obj->battle.can_attack == true)
            foe = which_button_click(obj, mouse_pos, foe);
    }
    if (obj->battle.can_attack == false) {
        clock_attack(obj);
    }
    return foe;
}
