/*
** EPITECH PROJECT, 2022
** create_text_dialogue.c
** File description:
** create the text for the dialogue
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "button.h"
#include "my.h"
#include "my_rpg.h"

static void create_text_dialogue(struct_object *object)
{
    sfText_setString(object->dialogue_wife.text_hero.text_invent, "OK");
    sfText_setString(object->dialogue_wife.text_wife.text_invent,
    "Go get a BAGUTTE");
    sfText_setString(object->dialogue_balk_anny.text_hero.text_invent,
    "Give BAGUETTE");
    sfText_setString(object->dialogue_balk_anny.text_balk_anny.text_invent,\
    "Never");
}

static void create_dialogue_wife(struct_object *object)
{
    object->dialogue_wife.text_hero.text_invent = sfText_create();
    object->dialogue_wife.text_hero.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->dialogue_wife.text_hero.text_invent,
    object->dialogue_wife.text_hero.font_text_invent);
    sfText_setCharacterSize(object->dialogue_wife.text_hero.text_invent, 40);
    sfText_setFillColor(object->dialogue_wife.text_hero.text_invent, sfWhite);
    sfText_setPosition(object->dialogue_wife.text_hero.text_invent,
    (sfVector2f){object->hero.position.x + 40, object->hero.position.y});
    object->dialogue_wife.text_wife.text_invent = sfText_create();
    object->dialogue_wife.text_wife.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->dialogue_wife.text_wife.text_invent,
    object->dialogue_wife.text_wife.font_text_invent);
    sfText_setCharacterSize(object->dialogue_wife.text_wife.text_invent, 40);
    sfText_setFillColor(object->dialogue_wife.text_wife.text_invent, sfWhite);
    sfText_setPosition(object->dialogue_wife.text_wife.text_invent,
    (sfVector2f){object->wife.position.x + 40, object->wife.position.y});
    object->dialogue_wife.can_print = true;
}

void create_new_text_dialogue(struct_object *obj)
{
    sfText_setString(obj->dialogue_wife.text_wife.text_invent,
    "Thank you honey, now your adventure is finished");
}

void create_dialogue(struct_object *object)
{
    create_dialogue_balk_anny(object);
    create_dialogue_wife(object);
    create_text_dialogue(object);
}
