/*
** EPITECH PROJECT, 2022
** create_mob.c
** File description:
** create a little mob for the first battle
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

void create_blob(struct_object *obj)
{
    obj->blob = malloc(sizeof(struct_charachter *) * 4);
    for (size_t x = 0; x < 4; x++) {
        obj->blob[x] = malloc(sizeof(struct_charachter));
        obj->blob[x]->texture =
        sfTexture_createFromFile("./assets/sprites/blob2.png", NULL);
        obj->blob[x]->texture_fight =
        sfTexture_createFromFile("./assets/sprites/blob.png", NULL);
        obj->blob[x]->sprite = sfSprite_create();
        obj->blob[x]->sprite_fight = sfSprite_create();
        obj->blob[x]->rect.top = 0;
        obj->blob[x]->rect.left = 0;
        obj->blob[x]->rect.width = 60;
        obj->blob[x]->rect.height = 34;
        sfSprite_setTexture(obj->blob[x]->sprite, obj->blob[x]->texture,
        sfTrue);
        sfSprite_setTexture(obj->blob[x]->sprite_fight,
        obj->blob[x]->texture_fight, sfTrue);
        sfSprite_setTextureRect(obj->blob[x]->sprite, obj->blob[x]->rect);
        sfSprite_setTextureRect(obj->blob[x]->sprite_fight,
        obj->blob[x]->rect);
        obj->blob[x]->death = false;
        obj->blob[x]->pv = 20;
        obj->blob[x]->x = x;
                obj->blob[x]->size_x = obj->blob[x]->rect.width;
        obj->blob[x]->size_y = obj->blob[x]->rect.height;
        obj->blob[x]->health = 20;
        sfSprite_setPosition(obj->blob[x]->sprite_fight,
        (sfVector2f){200, 700});
    }
    obj->blob[0]->position.x = 750;
    obj->blob[0]->position.y = 650;
    sfSprite_setPosition(obj->blob[0]->sprite, obj->blob[0]->position);
    obj->blob[1]->position.x = 300;
    obj->blob[1]->position.y = 250;
    sfSprite_setPosition(obj->blob[1]->sprite, obj->blob[1]->position);
    obj->blob[2]->position.x = 1000;
    obj->blob[2]->position.y = 250;
    sfSprite_setPosition(obj->blob[2]->sprite, obj->blob[2]->position);
    obj->blob[3]->position.x = 1450;
    obj->blob[3]->position.y = 650;
    sfSprite_setPosition(obj->blob[3]->sprite, obj->blob[3]->position);
}
