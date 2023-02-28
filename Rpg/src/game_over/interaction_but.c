/*
** EPITECH PROJECT, 2022
** interaction_but.c
** File description:
** put an interaction with our button
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "button.h"
#include "my.h"
#include "my_rpg.h"

static void pos_over2(sfRenderWindow *window, sfEvent *event,
struct_object *obj)
{
    while (sfRenderWindow_pollEvent(window, event))
        if (event->type == sfEvtMouseButtonPressed) {
            sfMusic_stop(obj->music_over.music);
            obj->play = 0;
        }
}

void pos_over(sfRenderWindow *window, sfEvent *event, struct_object *obj)
{
    sfVector2i pos_mouse = sfMouse_getPosition((const sfWindow *)window);

    if (pos_mouse.y >= 703 && pos_mouse.y <= 785) {
        if (pos_mouse.x >= 707 && pos_mouse.x <= 1024)
            pos_over2(window, event, obj);
    }
}
