/*
** EPITECH PROJECT, 2021
** init_player.c
** File description:
** initialisation player
*/

#include <ncurses.h>
#include <stdlib.h>
#include "includes/my_sokoban.h"

void init_struct(t_sok *sok)
{
    sok->num_boxes = 0;
    sok->num_boxes_ok = 0;
    sok->num_stores = 0;
    sok->size = 0;
    sok->col = 0;
    sok->row = 0;
    sok->x = 0;
    sok->y = 0;
    sok->end = 0;
    sok->buffer = NULL;
    sok->initial = NULL;
}

void get_player_pos(t_sok *sok)
{
    int x = 0;

    for (int y = 0; sok->buffer[y] != NULL; y++) {
        x = 0;
        for (; sok->buffer[y][x] != '\0' && sok->buffer[y][x] != 'P'; x++);
        if (sok->buffer[y][x] == 'P') {
            sok->x = x;
            sok->y = y;
            break;
        }
    }
}

void move_player(t_sok *sok, int key)
{
    if (key == KEY_LEFT)
        player_mvleft(sok);
    if (key == KEY_RIGHT)
        player_mvright(sok);
    if (key == KEY_UP)
        player_mvup(sok);
    if (key == KEY_DOWN)
        player_mvdown(sok);
}
