/*
** EPITECH PROJECT, 2022
** create_dialogue_balkanny.c
** File description:
** create the dialogue of balkanny
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "button.h"
#include "my.h"
#include "my_rpg.h"

static void create_dialogue_of_balk_anny(struct_object *object)
{
    object->dialogue_balk_anny.text_balk_anny.text_invent = sfText_create();
    object->dialogue_balk_anny.text_balk_anny.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->dialogue_balk_anny.text_balk_anny.text_invent,
    object->dialogue_balk_anny.text_balk_anny.font_text_invent);
    sfText_setCharacterSize(object->dialogue_balk_anny.text_balk_anny
    .text_invent, 40);
    sfText_setFillColor(object->dialogue_balk_anny.text_balk_anny.text_invent,
    sfWhite);
    sfText_setPosition(object->dialogue_balk_anny.text_balk_anny.text_invent,
    (sfVector2f){object->balk_anny.position.x,
    object->balk_anny.position.y + 20});
    object->dialogue_balk_anny.can_print = false;
}

void create_dialogue_balk_anny(struct_object *object)
{
    object->dialogue_balk_anny.text_hero.text_invent = sfText_create();
    object->dialogue_balk_anny.text_hero.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->dialogue_balk_anny.text_hero.text_invent,
    object->dialogue_balk_anny.text_hero.font_text_invent);
    sfText_setCharacterSize(object->dialogue_balk_anny.text_hero.text_invent,
    40);
    sfText_setFillColor(object->dialogue_balk_anny.text_hero.text_invent,
    sfWhite);
    create_dialogue_of_balk_anny(object);
}
