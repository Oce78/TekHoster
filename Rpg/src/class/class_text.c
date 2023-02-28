/*
** EPITECH PROJECT, 2022
** class_text.c
** File description:
** create the text of the class
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void destroy_class_text(struct_object *obj)
{
    sfFont_destroy(obj->text_class.font_text_invent);
    sfText_destroy(obj->text_class.text_invent);
}

void create_class_text(struct_object *obj)
{
    obj->text_class.text_invent = sfText_create();
    obj->text_class.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(obj->text_class.text_invent,
    obj->text_class.font_text_invent);
    sfText_setCharacterSize(obj->text_class.text_invent, 40);
    sfText_setFillColor(obj->text_class.text_invent, sfWhite);
    sfText_setString(obj->text_class.text_invent, "Choose your class");
    sfText_setPosition(obj->text_class.text_invent, (sfVector2f){765, 0});
}
