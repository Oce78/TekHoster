/*
** EPITECH PROJECT, 2022
** choose_class.C
** File description:
** make you choose your class
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

static void set_rect(struct_object *obj)
{
    obj->class[0]->rect.width = 641;
    obj->class[0]->rect.height = 900;
    sfSprite_setTextureRect(obj->class[0]->sprite, obj->class[0]->rect);
    obj->class[1]->rect.width = 519;
    obj->class[1]->rect.height = 700;
    sfSprite_setTextureRect(obj->class[1]->sprite, obj->class[1]->rect);
    obj->class[2]->rect.width = 512;
    obj->class[2]->rect.height = 481;
    sfSprite_setTextureRect(obj->class[2]->sprite, obj->class[2]->rect);
    obj->class[1]->position = (sfVector2f){640, 0};
    obj->class[2]->position = (sfVector2f){1280, 0};
    sfSprite_setPosition(obj->class[1]->sprite, obj->class[1]->position);
    sfSprite_setPosition(obj->class[2]->sprite, obj->class[2]->position);
}

static void init_class(struct_object *obj)
{
    obj->class = malloc(sizeof(class_t) * 3);
    for (int x = 0; x < 3; x++)
        obj->class[x] = malloc(sizeof(class_t));
    obj->class[0]->texture =
    sfTexture_createFromFile("ressource/Guerrier.jpg", NULL);
    obj->class[1]->texture =
    sfTexture_createFromFile("ressource/sorcerer.jpg", NULL);
    obj->class[2]->texture =
    sfTexture_createFromFile("ressource/ranger.jpg", NULL);
    for (int x = 0; x < 3; x++) {
        obj->class[x]->sprite = sfSprite_create();
        sfSprite_setTexture(obj->class[x]->sprite, obj->class[x]->texture,
        sfTrue);
        obj->class[x]->rect.top = 0;
        obj->class[x]->rect.left = 0;
    }
    set_rect(obj);
    sfSprite_setScale(obj->class[0]->sprite, (sfVector2f){1, 1.2});
    sfSprite_setScale(obj->class[1]->sprite, (sfVector2f){1.2, 1.5});
    sfSprite_setScale(obj->class[2]->sprite, (sfVector2f){1.3, 2.2});
}

static void destroy_class(struct_object *obj)
{
    for (int x = 0; x < 3; x++) {
        sfSprite_destroy(obj->class[x]->sprite);
        sfTexture_destroy(obj->class[x]->texture);
        free(obj->class[x]);
    }
    free(obj->class);
}

static void which_class_is_select(struct_object *obj, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 0 && mouse_pos.x < 640) {
        obj->stat->nmbr_class = 1;
        create_warrior(obj);
    } else if (mouse_pos.x >= 640 && mouse_pos.x < 1280) {
        obj->stat->nmbr_class = 2;
        create_spellcaster(obj);
    } else {
        obj->stat->nmbr_class = 3;
        create_ranger(obj);
    }
}

void choose_class(struct_object *object, sfRenderWindow *window)
{
    sfVector2i mouse_pos;

    object->stat = malloc(sizeof(stats_t));
    init_class(object);
    create_class_text(object);
    for (size_t x = 0; x < 3; x++)
        sfRenderWindow_drawSprite(window, object->class[x]->sprite, NULL);
    sfRenderWindow_drawText(window, object->text_class.text_invent, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &object->event.event)) {
        if (object->event.event.type == sfEvtMouseButtonPressed) {
            mouse_pos = sfMouse_getPosition((const sfWindow *)window);
            object->play = 2;
            which_class_is_select(object, mouse_pos);
            destroy_class(object);
        }
        if (object->event.event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
    }
}
