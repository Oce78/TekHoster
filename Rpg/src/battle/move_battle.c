/*
** EPITECH PROJECT, 2022
** move_battle.c
** File description:
** move sprites for the battle
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

static void move_foe(struct_object *object, struct_charachter foe)
{
    foe.rect.left += 62;
    if (foe.rect.left >= 720)
        foe.rect.left = 0;
    sfSprite_setTextureRect(foe.sprite_fight, foe.rect);
    sfRenderWindow_drawSprite(object->window.window, foe.sprite_fight, NULL);
}

static void move_spell_batt(struct_object *object)
{
    object->hero.rect.left += 47;
    if (object->hero.rect.left >= 111)
        object->hero.rect.left = 0;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
    sfRenderWindow_drawSprite(object->window.window, object->hero.sprite,
    NULL);
}

static void move_warrior_batt(struct_object *object)
{
    object->hero.rect.left += 38;
    if (object->hero.rect.left >= 114)
        object->hero.rect.left = 0;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
    sfRenderWindow_drawSprite(object->window.window, object->hero.sprite,
    NULL);
}

static void clock_battle(struct_object *object, struct_charachter foe)
{
    object->clock_battle.time =
    sfClock_getElapsedTime(object->clock_battle.clock);
    object->clock_battle.seconds = object->clock_battle.time.microseconds /
    1000000.0f;
    if (object->clock_battle.seconds > 0.2) {
        if (foe.x >= 0)
            move_foe(object, foe);
        if (object->stat->nmbr_class == 1)
            move_warrior_batt(object);
        else if (object->stat->nmbr_class == 2)
            move_spell_batt(object);
        else if (object->stat->nmbr_class == 3)
            move_ranger_batt(object);
        sfClock_restart(object->clock_battle.clock);
    }
}

void move_battle(struct_object *object, struct_charachter foe)
{
    clock_battle(object, foe);
}
