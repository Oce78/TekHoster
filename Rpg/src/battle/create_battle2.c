/*
** EPITECH PROJECT, 2022
** create_battle2.c
** File description:
** 2nd file for create sprite when the battle begin
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

void create_hero_battle(struct_object *obj)
{
    sfVector2f size = {2.0, 2.0};

    obj->hero.position = (sfVector2f){1700, 600};
    if (obj->stat->nmbr_class == 1)
        obj->hero.rect.top = 45;
    else if (obj->stat->nmbr_class == 2)
        obj->hero.rect.top = 48;
    else if (obj->stat->nmbr_class == 3)
        obj->hero.rect.top = 48;
    sfSprite_setTextureRect(obj->hero.sprite, obj->hero.rect);
    sfSprite_setPosition(obj->hero.sprite, obj->hero.position);
    sfSprite_setScale(obj->hero.sprite, size);
}
