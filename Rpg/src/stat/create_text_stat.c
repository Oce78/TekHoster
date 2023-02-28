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

void put_numbers_in_text(struct_object *object)
{
    sfText_setString(object->text_number_stat[0]->text_invent,
    itoa(object->stat->lvl));
    sfText_setString(object->text_number_stat[1]->text_invent,
    itoa(object->stat->exp));
    sfText_setString(object->text_number_stat[2]->text_invent,
    itoa(object->stat->strenght));
    sfText_setString(object->text_number_stat[3]->text_invent,
    itoa(object->stat->dext));
    sfText_setString(object->text_number_stat[4]->text_invent,
    itoa(object->stat->health));
    sfText_setString(object->text_number_stat[5]->text_invent,
    itoa(object->stat->wisdom));
    sfText_setString(object->text_number_stat[6]->text_invent, "-1");
}

void create_number_text_stat(struct_object *object)
{
    object->text_number_stat = malloc(sizeof(struct_text) * 7);

    for (int x = 0; x < 7; x++) {
        object->text_number_stat[x] = malloc(sizeof(struct_text));
        object->text_number_stat[x]->text_invent = sfText_create();
        object->text_number_stat[x]->font_text_invent =
        sfFont_createFromFile("ressource/cinzel.ttf");
        sfText_setFont(object->text_number_stat[x]->text_invent,
        object->text_number_stat[x]->font_text_invent);
        sfText_setCharacterSize(object->text_number_stat[x]->text_invent, 40);
        sfText_setFillColor(object->text_number_stat[x]->text_invent, sfWhite);
    }
    sfText_setPosition(object->text_number_stat[0]->text_invent,
    (sfVector2f){279, 505});
    sfText_setPosition(object->text_number_stat[1]->text_invent,
    (sfVector2f){445, 505});
    sfText_setPosition(object->text_number_stat[2]->text_invent,
    (sfVector2f){445, 560});
    sfText_setPosition(object->text_number_stat[3]->text_invent,
    (sfVector2f){445, 610});
    sfText_setPosition(object->text_number_stat[4]->text_invent,
    (sfVector2f){445, 655});
    sfText_setPosition(object->text_number_stat[5]->text_invent,
    (sfVector2f){445, 705});
    sfText_setPosition(object->text_number_stat[6]->text_invent,
    (sfVector2f){445, 755});
    put_numbers_in_text(object);
}
