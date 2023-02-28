/*
** EPITECH PROJECT, 2022
** create_gameover.c
** File description:
** create all we need for the game over screen
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

static void game_overback(struct_object *object)
{
    sfVector2f size = {1.5, 1.5};

    object->game_over.background_text =
    sfTexture_createFromFile("./assets/sprites/game-over.png", NULL);
    object->game_over.background = sfSprite_create();
    object->game_over.back.top = 0;
    object->game_over.back.left = 0;
    object->game_over.back.width = 1920;
    object->game_over.back.height = 1080;
    sfSprite_setScale(object->game_over.background, size);
    sfSprite_setTexture(object->game_over.background,
    object->game_over.background_text, sfTrue);
    sfSprite_setTextureRect(object->game_over.background,
    object->game_over.back);
}

static void create_game_over_music(struct_object *obj)
{
    sfMusic_stop(obj->music.music);
    obj->music_over.music =
    sfMusic_createFromFile("./assets/music/game_over.ogg");
    sfMusic_setVolume(obj->music_over.music, 80);
    sfMusic_play(obj->music_over.music);
}

static void create_button_over(struct_object *obj)
{
    sfVector2f pos = {700, 700};
    sfVector2f size = {1.5, 1.5};

    obj->but_over.texture =
    sfTexture_createFromFile("./assets/sprites/button_over.png", NULL);
    obj->but_over.sprite = sfSprite_create();
    sfSprite_setScale(obj->but_over.sprite, size);
    sfSprite_setPosition(obj->but_over.sprite, pos);
    sfSprite_setTexture(obj->but_over.sprite, obj->but_over.texture,
    sfTrue);
}

void create_over(struct_object *obj)
{
    game_overback(obj);
    create_button_over(obj);
    create_game_over_music(obj);
    obj->over = true;
}
