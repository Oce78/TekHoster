/*
** EPITECH PROJECT, 2021
** my_defender.c
** File description:
** main and help of my_defender
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"
#include <stdio.h>

static int open_menu(struct_object *object, sfRenderWindow *window,
t_gbl opti, float volume)
{   if (object->play == 0) {
        if (object->settings == 1) {
            window_settings(&opti, window, object, volume);
            return 1;
        }
        menu(object, window, opti);
        return 1;
    }
    return 0;
}

void boucle_inf(struct_object *object, sfRenderWindow *window, t_gbl opti,
float volume)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &object->event.event)) {
            if (object->event.event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        if (open_menu(object, window, opti, volume) == 1)
            continue;
        if (object->play == 1)
            choose_class(object, window);
        if (object->play == 2)
            second_window(object, window);
    }
}
