/*
** EPITECH PROJECT, 2022
** move_spell.c
** File description:
** move the spellcaster sprite
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

static void move_spell(struct_object *obj)
{
    obj->hero.rect.left += 47;
    if (obj->hero.rect.left >= 111)
        obj->hero.rect.left = 0;
    sfSprite_setTextureRect(obj->hero.sprite, obj->hero.rect);
    sfRenderWindow_drawSprite(obj->window.window, obj->hero.sprite, NULL);
}

void mouvement_spellback(struct_object *obj)
{
    obj->hero.position = sfSprite_getPosition(obj->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && obj->hero.position.x
    > 10) {
        obj->hero.rect.top = 48;
        obj->hero.position.x -= 10;
        move_spell(obj);
        if (obj->hero.position.x <= -90.00)
            obj->hero.position.x = 0;
    }
    sfSprite_setPosition(obj->hero.sprite, obj->hero.position);
}

void mouvement_spellfor(struct_object *object)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyRight) && object->hero.position.x
    < 1880) {
        object->hero.rect.top = 96;
        object->hero.position.x += 10;
        move_spell(object);
        if (object->hero.position.x >= 1920.00)
            object->hero.position.x = 0;
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

void mouvement_spellup(struct_object *object)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && object->hero.position.y
    > 10) {
        object->hero.rect.top = 144;
        object->hero.position.y -= 10;
        move_spell(object);
        if (object->hero.position.y <= -90.00)
            object->hero.position.y = 900;
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

void mouvement_spelldown(struct_object *object)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && object->hero.position.y
    < 980) {
        object->hero.rect.top = 0;
        object->hero.position.y += 10;
        move_spell(object);
        if (object->hero.position.y >= 1010.00)
            object->hero.position.y = 900;
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}
