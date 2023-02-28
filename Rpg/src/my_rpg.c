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

static void display_menu(sfRenderWindow *window, t_gbl opti)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, opti.backg.sprite, NULL);
    sfRenderWindow_drawSprite(window, opti.play.sprite, NULL);
    sfRenderWindow_drawSprite(window, opti.set_tings.sprite, NULL);
    sfRenderWindow_drawSprite(window, opti.quit.sprite, NULL);
    sfRenderWindow_display(window);
}

void menu(struct_object *object, sfRenderWindow *window, t_gbl opti)
{
    display_menu(window, opti);
    pos_play(window, object);
    pos_settings(window, object);
    pos_quit(window, object);
}

int menu_defender(struct_object *object)
{
    t_gbl opti;
    background(&opti);
    play(&opti);
    button_settings(&opti);
    button_quit(&opti);
    float volume = create_music(object);

    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    object->play = 0;
    object->settings = 0;
    object->create = false;
    object->battle.battle_beg = false;
    window = sfRenderWindow_create(mode, "Main Menu", sfResize | sfClose,\
    NULL);
    boucle_inf(object, window, opti, volume);
    destroy_object(object, window);
    return 0;
}

static int print_help (void)
{
    my_putstr("my_rpg - Baguette The Quest\n");
    return 0;
}

int main(int ac, char **av)
{
    struct_object *object = malloc(sizeof(struct_object));

    if (!object)
        return 84;
    if ((ac == 2) && (av[1][0] == '-') && (av[1][1] == 'h'))
        return print_help();
    else if (ac != 1) {
        my_putstr("Usage: my_defender [-h]\n");
        return 0;
    }
    menu_defender(object);
    return 0;
}
