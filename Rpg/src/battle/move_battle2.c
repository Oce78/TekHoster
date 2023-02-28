/*
** EPITECH PROJECT, 2022
** move_battle2.c
** File description:
** for move the hero on the battle
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void move_ranger_batt(struct_object *obj)
{
    obj->hero.rect.left += 37;
    if (obj->hero.rect.left >= 111)
        obj->hero.rect.left = 0;
    sfSprite_setTextureRect(obj->hero.sprite, obj->hero.rect);
    sfRenderWindow_drawSprite(obj->window.window, obj->hero.sprite, NULL);
}
