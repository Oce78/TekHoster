/*
** EPITECH PROJECT, 2021
** music.c
** File description:
** music menu
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_music(t_gbl *gbl)
{
    if (!(gbl->game.music =
    sfMusic_createFromFile("./assets/music/menu_music.ogg")))
        return (84);
    sfMusic_setVolume(gbl->game.music, 50);
    sfMusic_play(gbl->game.music);
    return 0;
}
