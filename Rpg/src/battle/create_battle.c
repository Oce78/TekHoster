/*
** EPITECH PROJECT, 2022
** create_battle.c
** File description:
** create the necessary for the battle of the RPG
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

static void create_music_battle(struct_object *obj)
{
    sfMusic_pause(obj->music.music);
    obj->music_battle.music =
    sfMusic_createFromFile("assets/music/battle_rpg.ogg");
    sfMusic_setVolume(obj->music_battle.music, 80);
    sfMusic_play(obj->music_battle.music);
}

static void create_battle_back(struct_object *object)
{
    sfVector2f size = {1.0, 0.8};

    object->battle.battle_back.background_text =
    sfTexture_createFromFile("./assets/sprites/battle_rpg.png", NULL);
    object->battle.battle_back.background = sfSprite_create();
    sfSprite_setScale(object->battle.battle_back.background, size);
    sfSprite_setTexture(object->battle.battle_back.background,
    object->battle.battle_back.background_text, sfTrue);
    sfSprite_setScale(object->battle.battle_back.background,
    (sfVector2f){3, 4.5});
}

static void create_clock_battle(struct_object *object)
{
    object->clock_battle.clock = sfClock_create();
}

struct_charachter init_battle(struct_object *object, struct_charachter foe)
{
    object->hero.recup = object->hero.position;
    create_text_battle(object, foe);
    create_battle_back(object);
    object->battle.can_attack = true;
    foe = create_button_battle(object, foe);
    create_hero_battle(object);
    create_music_battle(object);
    create_clock_battle(object);
    object->battle.battle_beg = true;
    return foe;
}
