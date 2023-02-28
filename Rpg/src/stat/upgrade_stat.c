/*
** EPITECH PROJECT, 2022
** upgrade_stat.c
** File description:
** upgrade_stat when click
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>

static void which_button_click_stat(struct_object *obj, sfVector2i mouse_pos)
{
    if (obj->stat->nbr_of_point >= 1) {
        if (mouse_pos.y <= 600)
            obj->stat->strenght += 1;
        else if (mouse_pos.y <= 660)
            obj->stat->dext += 1;
        else if (mouse_pos.y <= 710)
            obj->stat->health += 1;
        else if (mouse_pos.y <= 760)
            obj->stat->wisdom += 1;
        obj->stat->nbr_of_point -= 1;
    }
}

void create_button_stat(struct_object *obj)
{
    sfVector2i mouse_pos;

    if (obj->event.event.type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPosition((const sfWindow *)obj->window.window);
        if (mouse_pos.y >= 560 && mouse_pos.y <= 760 && mouse_pos.x >= 470 &&
        mouse_pos.x <= 520)
            which_button_click_stat(obj, mouse_pos);
    }
}
