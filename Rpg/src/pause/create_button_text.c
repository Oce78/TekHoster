/*
** EPITECH PROJECT, 2022
** create_button_text.c
** File description:
** create sprite of the button and the text of pause menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

static void create_text_pause(struct_object *object)
{
    sfVector2f pos = {800, 100};

    object->text_pause.text_invent = sfText_create();
    object->text_pause.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->text_pause.text_invent,
    object->text_pause.font_text_invent);
    sfText_setString(object->text_pause.text_invent, "PAUSE");
    sfText_setPosition(object->text_pause.text_invent, pos);
    sfText_setCharacterSize(object->text_pause.text_invent, 40);
    sfText_setFillColor(object->text_pause.text_invent, sfWhite);
}

static void button_continue(struct_object *object)
{
    sfVector2f pos = {500, 300};
    sfVector2f size = {2.5, 2.5};

    object->but_continue.texture =
    sfTexture_createFromFile("./assets/sprites/continue.png", NULL);
    object->but_continue.sprite = sfSprite_create();
    sfSprite_setScale(object->but_continue.sprite, size);
    sfSprite_setPosition(object->but_continue.sprite, pos);
    sfSprite_setTexture(object->but_continue.sprite,
    object->but_continue.texture, sfTrue);
}

static void button_exit(struct_object *object)
{
    sfVector2f pos = {500, 500};
    sfVector2f size = {2.5, 2.5};

    object->but_exit.texture =
    sfTexture_createFromFile("./assets/sprites/exit.png", NULL);
    object->but_exit.sprite = sfSprite_create();
    sfSprite_setScale(object->but_exit.sprite, size);
    sfSprite_setPosition(object->but_exit.sprite, pos);
    sfSprite_setTexture(object->but_exit.sprite, object->but_exit.texture,
    sfTrue);
}

void create_button(struct_object *object)
{
    create_text_pause(object);
    button_continue(object);
    button_exit(object);
}
