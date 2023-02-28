/*
** EPITECH PROJECT, 2022
** click_button.c
** File description:
** game button
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "button.h"
#include "my.h"
#include "my_rpg.h"

void pos_play(sfRenderWindow *window, struct_object *object)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 536 && mouse_pos.y <= 617)
        if (mouse_pos.x >= 738 && mouse_pos.x <= 1187)
            while (sfRenderWindow_pollEvent(window, &object->event.event))
                if (object->event.event.type == sfEvtMouseButtonPressed)
                    object->play = 1;
}

void pos_settings(sfRenderWindow* window, struct_object *object)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 630 && mouse_pos.y <= 720) {
        if (mouse_pos.x >= 738 && mouse_pos.x <= 1200) {
            while (sfRenderWindow_pollEvent(window, &object->event.event)) {
                if (object->event.event.type == sfEvtMouseButtonPressed) {
                    object->settings = 1;
                }
            }
        }
    }
}

void pos_quit(sfRenderWindow* window, struct_object *object)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 737 && mouse_pos.y <= 823) {
        if (mouse_pos.x >= 730 && mouse_pos.x <= 1200) {
            while (sfRenderWindow_pollEvent(window, &object->event.event)) {
                if (object->event.event.type == sfEvtMouseButtonPressed) {
                    sfRenderWindow_close(window);
                    break;
                }
            }
        }
    }
}

void click_voldown(sfRenderWindow *window, struct_object *obj, float volume)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 446 && mouse_pos.y <= 596) {
        if (mouse_pos.x >= 334 && mouse_pos.x <= 486) {
            while (sfRenderWindow_pollEvent(window, &obj->event.event)) {
                if (obj->event.event.type == sfEvtMouseButtonPressed) {
                    volume -= 10;
                    sfMusic_setVolume(obj->music.music, volume);
                }
            }
        }
    }
}

void click_volup(sfRenderWindow *window, struct_object *obj, float volume)
{
    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);

    if (mouse_pos.y >= 454 && mouse_pos.y <= 604) {
        if (mouse_pos.x >= 646 && mouse_pos.x <= 798) {
            while (sfRenderWindow_pollEvent(window, &obj->event.event)) {
                if (obj->event.event.type == sfEvtMouseButtonPressed) {
                    volume += 10;
                    sfMusic_setVolume(obj->music.music, volume);
                }
            }
        }
    }
}
