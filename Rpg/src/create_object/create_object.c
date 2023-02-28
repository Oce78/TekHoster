/*
** EPITECH PROJECT, 2021
** create_object
** File description:
** for runner
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

void create_clock(struct_object *object);
void create_back2(struct_object *object);
void create_back3(struct_object *object);
void create_back4(struct_object *object);

void create_warrior(struct_object *object)
{
    object->hero.texture =
    sfTexture_createFromFile("assets/sprites/warrior.png", NULL);
    object->hero.sprite = sfSprite_create();
    object->hero.position.x = 150;
    object->hero.position.y = 350;
    sfSprite_setTexture(object->hero.sprite, object->hero.texture, sfTrue);
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
    object->hero.rect.top = 0;
    object->hero.rect.left = 0;
    object->hero.rect.width = 38;
    object->hero.rect.height = 45;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
}

void create_background(struct_object *object)
{
    object->background.background_text =
    sfTexture_createFromFile("assets/sprites/map.png", NULL);
    object->background.background = sfSprite_create();
    sfSprite_setTexture(object->background.background,
    object->background.background_text, sfTrue);
    object->background.back.top = 500;
    object->background.back.left = 0;
    object->background.back.width = 2048;
    object->background.back.height = 2048;
    sfSprite_setTextureRect(object->background.background,
    object->background.back);
}

sfRenderWindow *create_window(struct_object *object)
{
    object->window.mode.width = 1920;
    object->window.mode.height = 1080;
    object->window.mode.bitsPerPixel = 32;
    object->window.window = sfRenderWindow_create(object->window.mode,
    "j'adore la csfml", sfClose,  NULL);

    return (object->window.window);
}

void create_object(struct_object *object)
{
    create_background(object);
    create_balk_anny(object);
    create_wife(object);
    create_blob(object);
    create_inventory(object);
    create_text_inventory(object);
    create_clock(object);
    create_clock_attack(object);
    create_stat(object);
    create_dialogue(object);
    create_clock_dialogue(object);
}
