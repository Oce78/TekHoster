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
#include "my_lib.h"
#include "my.h"

void create_ranger(struct_object *object)
{
    object->hero.texture =
    sfTexture_createFromFile("assets/sprites/ranger.png", NULL);
    object->hero.sprite = sfSprite_create();
    object->hero.position.x = 150;
    object->hero.position.y = 350;
    sfSprite_setTexture(object->hero.sprite, object->hero.texture, sfTrue);
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
    object->hero.rect.top = 0;
    object->hero.rect.left = 0;
    object->hero.rect.width = 37;
    object->hero.rect.height = 48;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
}

void create_spellcaster(struct_object *object)
{
    object->hero.texture =
    sfTexture_createFromFile("assets/sprites/spellcaster.png", NULL);
    object->hero.sprite = sfSprite_create();
    object->hero.position.x = 150;
    object->hero.position.y = 350;
    sfSprite_setTexture(object->hero.sprite, object->hero.texture, sfTrue);
    sfSprite_setPosition(object->hero.sprite, object->hero.position);
    object->hero.rect.top = 0;
    object->hero.rect.left = 0;
    object->hero.rect.width = 47;
    object->hero.rect.height = 48;
    sfSprite_setTextureRect(object->hero.sprite, object->hero.rect);
}

void create_balk_anny(struct_object *obj)
{
    obj->balk_anny.texture =
    sfTexture_createFromFile("assets/sprites/idle_balk.png", NULL);
    obj->balk_anny.texture_fight =
    sfTexture_createFromFile("assets/sprites/balk_anny2.png", NULL);
    obj->balk_anny.sprite = sfSprite_create();
    obj->balk_anny.sprite_fight = sfSprite_create();
    obj->balk_anny.position.x = 1200;
    obj->balk_anny.position.y = 590;
    sfSprite_setTexture(obj->balk_anny.sprite,
    obj->balk_anny.texture, sfTrue);
    sfSprite_setTexture(obj->balk_anny.sprite_fight,
    obj->balk_anny.texture_fight, sfTrue);
    sfSprite_setPosition(obj->balk_anny.sprite,
    obj->balk_anny.position);
    sfSprite_setPosition(obj->balk_anny.sprite_fight, (sfVector2f){200, 600});
    obj->balk_anny.rect.top = 0;
    obj->balk_anny.rect.left = 0;
    obj->balk_anny.rect.width = 43;
    obj->balk_anny.rect.height = 48;
    obj->balk_anny.pv = 50;
    obj->balk_anny.x = -1;
    obj->balk_anny.health = 25;
    obj->balk_anny.death = false;
    obj->balk_anny.size_x = obj->balk_anny.rect.width;
    obj->balk_anny.size_y = obj->balk_anny.rect.height;
    sfSprite_setTextureRect(obj->balk_anny.sprite_fight,
    obj->balk_anny.rect);
    sfSprite_setScale(obj->balk_anny.sprite_fight, (sfVector2f){2.0, 2.0});
}

void create_clock(struct_object *object)
{
    object->clock.clock = sfClock_create();
}

float create_music(struct_object *object)
{
    float volume = 80;

    object->music.music =
    sfMusic_createFromFile("assets/music/rpg_gameplay.ogg");
    sfMusic_setVolume(object->music.music, volume);

    return (volume);
}
