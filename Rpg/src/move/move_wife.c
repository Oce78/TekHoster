/*
** EPITECH PROJECT, 2022
** move_wife.c
** File description:
** move the sprite of the wife on the map
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void move_wife(struct_object *object)
{
    object->wife.rect.left += 33;
    if (object->wife.rect.left >= 99)
        object->wife.rect.left = 0;
    sfSprite_setTextureRect(object->wife.sprite, object->wife.rect);
    sfRenderWindow_drawSprite(object->window.window, object->wife.sprite,
    NULL);
}
