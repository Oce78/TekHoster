/*
** EPITECH PROJECT, 2021
** my_defender.c
** File description:
** main and help of my_runner
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my.h"
#include <stdio.h>

static void settings_render(t_gbl *opti, sfRenderWindow *window,
struct_object *obj)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, opti->backg.sprite, NULL);
    sfRenderWindow_drawSprite(window, opti->volumed.sprite, NULL);
    sfRenderWindow_drawSprite(window, opti->volumeu.sprite, NULL);
    sfRenderWindow_drawSprite(window, obj->return_settings.sprite, NULL);
    sfRenderWindow_display(window);

}

static void background_settings(t_gbl *opti)
{
    opti->backg.texture =
    sfTexture_createFromFile("./assets/sprites/settings.png", NULL);
    opti->backg.sprite = sfSprite_create();
    sfSprite_setTexture(opti->backg.sprite, opti->backg.texture, sfTrue);
    sfSprite_setScale(opti->backg.sprite, (sfVector2f){2.5, 2.0});
}

static void button_volume_down(t_gbl *opti)
{
    sfVector2f pos = (sfVector2f) {300, 430};
    opti->volumed.texture =
    sfTexture_createFromFile("./assets/sprites/volume_minus.png", NULL);
    sfVector2f size = {2.0, 2.0};

    opti->volumed.sprite = sfSprite_create();
    sfSprite_setScale(opti->volumed.sprite, size);
    sfSprite_setPosition(opti->volumed.sprite, pos);
    sfSprite_setTexture(opti->volumed.sprite, opti->volumed.texture, sfTrue);
}

static void button_volume_up(t_gbl *opti)
{
    sfVector2f pos = {600, 430};
    sfVector2f size = {2.0, 2.0};

    opti->volumeu.texture =
    sfTexture_createFromFile("./assets/sprites/volume_plus.png", NULL);
    opti->volumeu.sprite = sfSprite_create();
    sfSprite_setScale(opti->volumeu.sprite, size);
    sfSprite_setPosition(opti->volumeu.sprite, pos);
    sfSprite_setTexture(opti->volumeu.sprite, opti->volumeu.texture, sfTrue);
}

int window_settings(t_gbl *opti, sfRenderWindow *window, struct_object *obj,
float volume)
{
    background_settings(opti);
    create_return_menu(obj);
    button_volume_down(opti);
    button_volume_up(opti);
    settings_render(opti, window, obj);
    click_voldown(window, obj, volume);
    click_volup(window, obj, volume);
    click_return(window, obj);
    return (0);
}
