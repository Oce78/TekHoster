/*
** EPITECH PROJECT, 2022
** create_stat.c
** File description:
** create_stat
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

#define TOTALE_CASE_1 28
#define TOTALE_CASE 27

void destroy_stat(struct_object *object)
{
    for (size_t x = 0; x < 7; x++) {
        sfText_destroy(object->text_number_stat[x]->text_invent);
        sfFont_destroy(object->text_number_stat[x]->font_text_invent);
        free(object->text_number_stat[x]);
    }
    sfText_destroy(object->text_stat.text_invent);
    sfFont_destroy(object->text_stat.font_text_invent);
    free(object->text_number_stat);
    sfSprite_destroy(object->stat->stat_s);
    sfTexture_destroy(object->stat->stat_t);
    free(object->stat);
}

void create_text_stat(struct_object *object)
{
    sfVector2f pos_text = {330, 450};

    object->text_stat.text_invent = sfText_create();
    object->text_stat.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->text_stat.text_invent,
    object->text_stat.font_text_invent);
    sfText_setString(object->text_stat.text_invent, "stat");
    sfText_setPosition(object->text_stat.text_invent, pos_text);
    sfText_setCharacterSize(object->text_stat.text_invent, 40);
    sfText_setFillColor(object->text_stat.text_invent, sfWhite);
}

void create_stat(struct_object *object)
{
    sfVector2f scale = {2, 2};

    object->stat->stat_t =
    sfTexture_createFromFile("ressource/stat.png", NULL);
    object->stat->stat_s = sfSprite_create();
    object->stat->used = true;
    object->stat->stat_r.top = 0;
    object->stat->stat_r.left = 0;
    object->stat->stat_r.height = 150;
    object->stat->stat_r.width = 160;
    object->stat->pos.x = 200;
    object->stat->pos.y = 500;
    object->stat->lvl = 1;
    object->stat->exp = 0;
    object->stat->nbr_of_point = 0;
    sfSprite_setScale(object->stat->stat_s, scale);
    sfSprite_setTexture(object->stat->stat_s, object->stat->stat_t, sfTrue);
    sfSprite_setTextureRect(object->stat->stat_s, object->stat->stat_r);
    sfSprite_setPosition(object->stat->stat_s, object->stat->pos);
    create_text_stat(object);
    give_stat(object->stat);
    create_number_text_stat(object);
}

void print_stat(struct_object *object, sfRenderWindow *window)
{
    for (int a = 0; a < TOTALE_CASE; a++)
        if (object->stat->used)
            sfRenderWindow_drawSprite(window, object->stat->stat_s, NULL);
}
