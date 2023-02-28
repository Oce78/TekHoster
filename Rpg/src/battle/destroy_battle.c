/*
** EPITECH PROJECT, 2022
** destroy_end_battle
** File description:
** destroy all in the end of the fight
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"

void destroy_battle(struct_object *object)
{
    sfMusic_destroy(object->music_battle.music);
    sfSprite_destroy(object->battle.battle_back.background);
    sfTexture_destroy(object->battle.battle_back.background_text);
    sfClock_destroy(object->clock_battle.clock);
    for (size_t x = 0; x < 6; x++) {
        sfText_destroy(object->battle.text_battle[x]->text_invent);
        sfFont_destroy(object->battle.text_battle[x]->font_text_invent);
        free(object->battle.text_battle[x]);
    }
    free(object->battle.text_battle);
}
