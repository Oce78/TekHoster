/*
** EPITECH PROJECT, 2022
** create_text_stat.c
** File description:
** create the text for the stat
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "button.h"
#include "my.h"
#include "my_rpg.h"

void put_text_in_battle(struct_object *object, struct_charachter foe)
{
    sfText_setString(object->battle.text_battle[0]->text_invent,
    my_strcat("health = ", itoa(object->stat->pv)));
    sfText_setString(object->battle.text_battle[1]->text_invent,
    my_strcat("health = ", itoa(foe.pv)));
    sfText_setString(object->battle.text_battle[2]->text_invent,
    "Attack:");
    sfText_setString(object->battle.text_battle[3]->text_invent,
    "Punch");
    sfText_setString(object->battle.text_battle[4]->text_invent,
    "Throw");
    sfText_setString(object->battle.text_battle[5]->text_invent,
    "Cast Magic");
}

void create_text_battle(struct_object *object, struct_charachter foe)
{
    object->battle.text_battle = malloc(sizeof(struct_text) * 6);
    for (int x = 0; x < 6; x++) {
        object->battle.text_battle[x] = malloc(sizeof(struct_text));
        object->battle.text_battle[x]->text_invent = sfText_create();
        object->battle.text_battle[x]->font_text_invent =
        sfFont_createFromFile("ressource/cinzel.ttf");
        sfText_setFont(object->battle.text_battle[x]->text_invent,
        object->battle.text_battle[x]->font_text_invent);
        sfText_setCharacterSize(object->battle.text_battle[x]->text_invent,
        40);
        sfText_setFillColor(object->battle.text_battle[x]->text_invent,
        sfWhite);
    }
    sfText_setPosition(object->battle.text_battle[0]->text_invent,
    (sfVector2f){1650, 50});
    sfText_setPosition(object->battle.text_battle[1]->text_invent,
    (sfVector2f){20, 50});
    sfText_setPosition(object->battle.text_battle[2]->text_invent,
    (sfVector2f){850, 900});
    sfText_setPosition(object->battle.text_battle[3]->text_invent,
    (sfVector2f){620, 950});
    sfText_setPosition(object->battle.text_battle[4]->text_invent,
    (sfVector2f){850, 950});
    sfText_setPosition(object->battle.text_battle[5]->text_invent,
    (sfVector2f){1050, 950});
    put_text_in_battle(object, foe);
}
