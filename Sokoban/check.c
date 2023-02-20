/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** check functions
*/

#include <stdlib.h>
#include "includes/my_sokoban.h"

int check_end(t_sok *sok)
{
    int x = 0;
    int y = 0;
    int count = 0;

    sok->num_boxes_ok = 0;
    for (y = 0; sok->buffer[y] != NULL; y++)
        for (x = 0; sok->buffer[y][x] != '\0'; x++)
            is_end(sok, y, x) == 1 ? count++ : 0;
    if (sok->num_boxes == sok->num_boxes_ok)
        sok->end = 1;
    if (sok->num_boxes == count)
        sok->end = 2;
    if (sok->end != 0)
        return 1;
    return 0;
}

int is_end(t_sok *sok, int y, int x)
{
    char **sb = sok->buffer;

    (sb[y][x] == 'X' && (sok->initial[y][x] == 'O')) ? sok->num_boxes_ok++ : 0;
    if (sb[y][x] == 'X' && (sok->initial[y][x] != 'O')) {
        if ((sb[y][x - 1] == '#') && (sb[y + 1][x] == '#'))
            return 1;
        if ((sb[y][x - 1] == '#') && (sb[y - 1][x] == '#'))
            return 1;
        if ((sb[y][x + 1] == '#') && (sb[y + 1][x] == '#'))
            return 1;
        if ((sb[y][x + 1] == '#') && (sb[y - 1][x] == '#'))
            return 1;
    }
    return 0;
}
