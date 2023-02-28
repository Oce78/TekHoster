/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** un géométrie dash
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

int my_putchar(char c);
int my_putstr(char *str);

static void analyse_events_2(struct_object *object)
{
    if (object->battle.battle_beg == true) {
        object->current_ennemy = create_button_battle(object,
        object->current_ennemy);
        move_battle(object, object->current_ennemy);
    }
    if ((object->print_inventory == true || object->print_stat == true) &&
        sfKeyboard_isKeyPressed(sfKeyM)) {
        object->print_inventory = false;
        object->print_stat = false;
    }
    if (object->print_inventory == false && object->print_stat == false &&
    sfKeyboard_isKeyPressed(sfKeyEscape))
        object->print_pause = true;
}

static void analyse_events(sfRenderWindow *window, struct_object *object)
{
    if (object->event.event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        object->print_inventory = true;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        object->print_stat = true;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        verif_proxi_balk_anny(object);
        verif_proxi_wife(object);
    }
    analyse_events_2(object);
}

static void init_play(struct_object *object)
{
    if (object->create == false) {
        object->print_inventory = false;
        object->print_stat = false;
        object->print_pause = false;
        object->battle.battle_beg = false;
        object->bag_in_invent = false;
        object->over = false;
        create_object(object);
        create_inventory(object);
        create_button(object);
        object->create = true;
        sfMusic_play(object->music.music);
        sfClock_restart(object->dialogue_wife.clock.clock);
    }
}

int second_window(struct_object *object, sfRenderWindow *window)
{
    object->window.window = window;
    init_play(object);
    if (object->print_stat == true)
        create_button_stat(object);
    if (object->battle.battle_beg == true) {
        start_battle(object, object->current_ennemy);
    }
    if (object->dialogue_balk_anny.can_print == true)
        clock_dialogue_balk_anny(object);
    if (object->dialogue_wife.can_print == true)
        clock_dialogue_wife(object);
    move_object(object, window);
    put_numbers_in_text(object);
    verif_if_contact(object);
    render_window(object, window);
    while (sfRenderWindow_pollEvent(window, &object->event.event))
        analyse_events(window, object);
    return (0);
}
