/*
** EPITECH PROJECT, 2021
** move_object
** File description:
** for runner
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void move_warrior(struct_object *object, sfRenderWindow *window)
{
    object->hero.rect.left += 38;
    if (object->hero.rect.left >= 114)
        object->hero.rect.left = 0;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
    sfRenderWindow_drawSprite(window, object->hero.sprite, NULL);
}

void mouvement_x(struct_object *object, sfRenderWindow *window)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyRight) && object->hero.position.x
    < 1880) {
        object->hero.rect.top = 90;
        object->hero.position.x += 10;
        move_warrior(object, window);
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

static void movement_per_class(struct_object *object, sfRenderWindow *window)
{
    if (object->stat->nmbr_class == 1 &&
    object->dialogue_wife.can_print == false) {
        mouvement_x(object, window);
        mouvement_x_back(object, window);
        mouvement_y_up(object, window);
        mouvement_y_down(object, window);
    }
    if (object->stat->nmbr_class == 2 &&
    object->dialogue_wife.can_print == false) {
        mouvement_spellfor(object);
        mouvement_spellback(object);
        mouvement_spellup(object);
        mouvement_spelldown(object);
    }
    if (object->stat->nmbr_class == 3 &&
    object->dialogue_wife.can_print == false) {
        mouvement_rangerfor(object);
        mouvement_rangerback(object);
        mouvement_rangerup(object);
        mouvement_rangerdown(object);
    }
}

void clock(struct_object *object, sfRenderWindow *window)
{
    object->clock.time = sfClock_getElapsedTime(object->clock.clock);
    object->clock.seconds = object->clock.time.microseconds / 1000000.0f;
    if (object->clock.seconds > 0.2) {
        movement_per_class(object, window);
        move_idle_balk(object);
        move_blob(object);
        move_wife(object);
        sfClock_restart(object->clock.clock);
    }
}

void move_object(struct_object *object, sfRenderWindow *window)
{
    if (object->print_pause == false && object->battle.battle_beg == false)
        clock(object, window);
}
