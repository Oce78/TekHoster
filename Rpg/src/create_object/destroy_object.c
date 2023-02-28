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

void destroy_music(struct_object *object)
{
    sfMusic_destroy(object->music.music);
    if (object->battle.battle_beg == true)
    if (object->stat->pv <= 0)
        sfMusic_destroy(object->music_over.music);
}

void destroy_characters(struct_object *object)
{
        sfSprite_destroy(object->hero.sprite);
        sfTexture_destroy(object->hero.texture);
        sfSprite_destroy(object->balk_anny.sprite);
        sfTexture_destroy(object->balk_anny.texture);
        sfTexture_destroy(object->balk_anny.texture_fight);
        sfSprite_destroy(object->balk_anny.sprite_fight);
        for (size_t x = 0; x < 4; x++) {
            sfTexture_destroy(object->blob[x]->texture_fight);
            sfSprite_destroy(object->blob[x]->sprite_fight);
            free(object->blob[x]);
        }
        free(object->blob);
        sfSprite_destroy(object->wife.sprite);
        sfTexture_destroy(object->wife.texture);
}

void destroy_background(struct_object *object)
{
    sfSprite_destroy(object->background.background);
    sfTexture_destroy(object->background.background_text);
    if (object->stat->pv <= 0) {
        sfSprite_destroy(object->game_over.background);
        sfTexture_destroy(object->game_over.background_text);
    }
}

void destroy_text(struct_object *object)
{
    sfText_destroy(object->text_invetory.text_invent);
    sfFont_destroy(object->text_invetory.font_text_invent);
    sfText_destroy(object->text_pause.text_invent);
    sfFont_destroy(object->text_pause.font_text_invent);
}

void destroy_object(struct_object *object, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (object->play == 2) {
        if (object->stat->pv <= 0) {
            sfSprite_destroy(object->but_over.sprite);
            sfTexture_destroy(object->but_over.texture);
        }
        destroy_text(object);
        destroy_characters(object);
        destroy_inventory(object);
        sfClock_destroy(object->clock.clock);
        sfSprite_destroy(object->but_continue.sprite);
        sfTexture_destroy(object->but_continue.texture);
        sfSprite_destroy(object->but_exit.sprite);
        sfTexture_destroy(object->but_exit.texture);
        destroy_stat(object);
    }
    destroy_music(object);
    free(object);
}
