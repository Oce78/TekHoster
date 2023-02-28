/*
** EPITECH PROJECT, 2022
** create_butt_return.c
** File description:
** create a button to return menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "my_rpg.h"
#include "my_lib.h"
#include <stdio.h>

void create_return_menu(struct_object *obj)
{
    sfVector2f pos = {700, 700};
    sfVector2f size = {1.5, 1.5};

    obj->return_settings.texture =
    sfTexture_createFromFile("./assets/sprites/button_over.png", NULL);
    obj->return_settings.sprite = sfSprite_create();
    sfSprite_setScale(obj->return_settings.sprite, size);
    sfSprite_setPosition(obj->return_settings.sprite, pos);
    sfSprite_setTexture(obj->return_settings.sprite,
    obj->return_settings.texture, sfTrue);
}
