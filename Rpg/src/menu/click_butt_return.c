/*
** EPITECH PROJECT, 2022
** click_butt_return.c
** File description:
** click the button for return to the menu
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/my_rpg.h"
#include "../includes/button.h"
#include "../includes/my.h"
#include "../includes/my_rpg.h"

static void click_return2(sfRenderWindow *window, struct_object *object)
{
    while (sfRenderWindow_pollEvent(window, &object->event.event)) {
        if (object->event.event.type == sfEvtMouseButtonPressed)
            object->settings = 0;
    }
}

void click_return(sfRenderWindow *window, struct_object *object)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 702 && mouse_pos.y <= 787) {
        if (mouse_pos.x >= 705 && mouse_pos.x <= 1028)
            click_return2(window, object);
    }
}
