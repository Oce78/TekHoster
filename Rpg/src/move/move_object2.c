/*
** EPITECH PROJECT, 2021
** move_object
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

void mouvement_x_back(struct_object *object, sfRenderWindow *window)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && object->hero.position.x
    > 10) {
        object->hero.rect.top = 45;
        object->hero.position.x -= 10;
        move_warrior(object, window);
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

void mouvement_y_up(struct_object *object, sfRenderWindow *window)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && object->hero.position.y
    > 10) {
        object->hero.rect.top = 135;
        object->hero.position.y -= 10;
        move_warrior(object, window);
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

void mouvement_y_down(struct_object *object, sfRenderWindow *window)
{
    object->hero.position = sfSprite_getPosition(object->hero.sprite);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && object->hero.position.y
    < 980) {
        object->hero.rect.top = 0;
        object->hero.position.y += 10;
        move_warrior(object, window);
    }
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
}

void move_idle_balk(struct_object *obj)
{
    obj->balk_anny.rect.left += 43;
    if (obj->balk_anny.rect.left >= 100)
        obj->balk_anny.rect.left = 0;
    sfSprite_setTextureRect(obj->balk_anny.sprite,
    obj->balk_anny.rect);
    sfRenderWindow_drawSprite(obj->window.window, obj->balk_anny.sprite,
    NULL);
}

void move_blob(struct_object *obj)
{
    for (size_t x = 0; x < 4; x++) {
        obj->blob[x]->rect.left += 62;
        if (obj->blob[x]->rect.left >= 720)
            obj->blob[x]->rect.left = 0;
        sfSprite_setTextureRect(obj->blob[x]->sprite, obj->blob[x]->rect);
        sfRenderWindow_drawSprite(obj->window.window, obj->blob[x]->sprite,
        NULL);
    }
}
