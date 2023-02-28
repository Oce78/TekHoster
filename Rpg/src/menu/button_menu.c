/*
** EPITECH PROJECT, 2021
** button_menu.c
** File description:
** button of the menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"

void play(t_gbl *opti)
{
    sfVector2f pos = (sfVector2f) {735, 530};
    opti->play.texture =
    sfTexture_createFromFile("./assets/sprites/button_play.png", NULL);
    sfVector2f size = {2.5, 2.5};

    opti->play.sprite = sfSprite_create();
    sfSprite_setScale(opti->play.sprite, size);
    sfSprite_setPosition(opti->play.sprite, pos);
    sfSprite_setTexture(opti->play.sprite, opti->play.texture, sfTrue);
}

void button_settings(t_gbl *opti)
{
    sfVector2f pos = (sfVector2f) {735, 630};
    opti->set_tings.texture =
    sfTexture_createFromFile("./assets/sprites/button_settings.png", NULL);
    sfVector2f size = {2.5, 2.5};

    opti->set_tings.sprite = sfSprite_create();
    sfSprite_setScale(opti->set_tings.sprite, size);
    sfSprite_setPosition(opti->set_tings.sprite, pos);
    sfSprite_setTexture(opti->set_tings.sprite, opti->set_tings.texture,
    sfTrue);
}

void button_quit(t_gbl *opti)
{
    sfVector2f pos = (sfVector2f) {735, 730};
    opti->quit.texture =
    sfTexture_createFromFile("./assets/sprites/button_quit.png", NULL);
    sfVector2f size = {2.5, 2.5};

    opti->quit.sprite = sfSprite_create();
    sfSprite_setScale(opti->quit.sprite, size);
    sfSprite_setPosition(opti->quit.sprite, pos);
    sfSprite_setTexture(opti->quit.sprite, opti->quit.texture, sfTrue);
}
