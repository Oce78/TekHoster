/*
** EPITECH PROJECT, 2022
** create_inventory.c
** File description:
** create_inventory
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

void destroy_inventory(struct_object *object)
{
    for (size_t x = 0; x < TOTALE_CASE; x++) {
        sfSprite_destroy(object->inventory[x]->inv_s);
        sfTexture_destroy(object->inventory[x]->inv_t);
        free(object->inventory[x]);
    }
    free(object->inventory);
}

void create_text_inventory(struct_object *object)
{
    sfVector2f pos_text = {900, 400};

    object->text_invetory.text_invent = sfText_create();
    object->text_invetory.font_text_invent =
    sfFont_createFromFile("ressource/cinzel.ttf");
    sfText_setFont(object->text_invetory.text_invent,
    object->text_invetory.font_text_invent);
    sfText_setString(object->text_invetory.text_invent, "inventory");
    sfText_setPosition(object->text_invetory.text_invent, pos_text);
    sfText_setCharacterSize(object->text_invetory.text_invent, 40);
    sfText_setFillColor(object->text_invetory.text_invent, sfWhite);
}

void create_inventory(struct_object *object)
{
    size_t a = 0;
    sfVector2f scale = {1.5, 1.5};

    object->inventory = malloc(sizeof(struct_inventory *) * TOTALE_CASE_1);
    object->inventory[TOTALE_CASE] = NULL;
    for (; a < TOTALE_CASE; a++) {
        object->inventory[a] = malloc(sizeof(struct_inventory));
        object->inventory[a]->inv_t =
        sfTexture_createFromFile("ressource/inventory.png", NULL);
        object->inventory[a]->inv_s = sfSprite_create();
        object->inventory[a]->used = true;
        object->inventory[a]->inv_r.top = 0;
        object->inventory[a]->inv_r.left = 0;
        object->inventory[a]->inv_r.height = 200;
        object->inventory[a]->inv_r.width = 340;
        object->inventory[a]->pos.x = 900;
        object->inventory[a]->pos.y = 500;
        sfSprite_setScale(object->inventory[a]->inv_s, scale);
        sfSprite_setTexture(object->inventory[a]->inv_s,
        object->inventory[a]->inv_t, sfTrue);
        sfSprite_setTextureRect(object->inventory[a]->inv_s,
        object->inventory[a]->inv_r);
        sfSprite_setPosition(object->inventory[a]->inv_s,
        object->inventory[a]->pos);
    }
}
