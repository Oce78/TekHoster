/*
** EPITECH PROJECT, 2021
** nackground_menu.c
** File description:
** background menu of my_defender
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_lib.h"

void background(t_gbl *opti)
{
    opti->backg.texture =
    sfTexture_createFromFile("./assets/sprites/background_menu.png", NULL);
    sfVector2f size = {1.0, 0.8};
    opti->backg.sprite = sfSprite_create();
    sfSprite_setScale(opti->backg.sprite, size);
    sfSprite_setTexture(opti->backg.sprite, opti->backg.texture, sfTrue);
}
