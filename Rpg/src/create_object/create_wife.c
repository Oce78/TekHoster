/*
** EPITECH PROJECT, 2022
** create_wife.c
** File description:
** create the wife sprite and put it on the map
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void create_wife(struct_object *object)
{
    object->wife.texture =
    sfTexture_createFromFile("assets/sprites/wife.png", NULL);
    object->wife.sprite = sfSprite_create();
    object->wife.position.x = 250;
    object->wife.position.y = 420;
    object->wife.rect.top = 0;
    object->wife.rect.left = 0;
    object->wife.rect.width = 33;
    object->wife.rect.height = 46;
    object->wife.size_x = 33;
    object->wife.size_y = 46;
    sfSprite_setTexture(object->wife.sprite, object->wife.texture, sfTrue);
    sfSprite_setPosition(object->wife.sprite, object->wife.position);
    sfSprite_setTextureRect(object->wife.sprite, object->wife.rect);
}
