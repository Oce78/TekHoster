/*
** EPITECH PROJECT, 2022
** create_bag.c
** File description:
** create the baguette sprite on the inventory
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void create_bag(struct_object *object)
{
    object->bag.texture =
    sfTexture_createFromFile("assets/sprites/baguette.png", NULL);
    object->bag.sprite = sfSprite_create();
    object->bag.position.x = 920;
    object->bag.position.y = 510;
    object->bag.rect.top = 17;
    object->bag.rect.left = 12;
    object->bag.rect.width = 220;
    object->bag.rect.height = 220;
    sfSprite_setTexture(object->bag.sprite, object->bag.texture, sfTrue);
    sfSprite_setTextureRect(object->bag.sprite, object->bag.rect);
    sfSprite_setPosition(object->bag.sprite, object->bag.position);
    sfSprite_setScale(object->bag.sprite, (sfVector2f){0.2, 0.2});
}
