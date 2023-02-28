/*
** EPITECH PROJECT, 2022
** main_menu.c
** File description:
** game menu
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

int main_menu(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "Menu", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_display(window);
    }
    return 0;
}
