/*
** EPITECH PROJECT, 2021
** move_player.c
** File description:
** move player left, right, up, down
*/
#include "includes/my_sokoban.h"

void player_mvleft(t_sok *sok)
{
    char **pos = sok->buffer;
    int x = sok->x;
    int y = sok->y;

    if ((pos[y][x - 1] == 'X' && pos[y][x - 2] == ' ') ||
        (pos[y][x - 1] == 'X' && pos[y][x - 2] == 'O')) {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y][x - 1] = 'P';
        pos[y][x - 2] = 'X';
        sok->x -= 1;
    } else if (pos[y][x - 1] == ' ' || pos[y][x - 1] == 'O') {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y][x - 1] = 'P';
        sok->x -= 1;
    }
}

void player_mvright(t_sok *sok)
{
    char **pos = sok->buffer;
    int x = sok->x;
    int y = sok->y;

    if ((pos[y][x + 1] == 'X' && pos[y][x + 2] == ' ') ||
        (pos[y][x + 1] == 'X' && pos[y][x + 2] == 'O')) {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y][x + 1] = 'P';
        pos[y][x + 2] = 'X';
        sok->x += 1;
    } else if (pos[y][x + 1] == ' ' || pos[y][x + 1] == 'O') {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y][x + 1] = 'P';
        sok->x += 1;
    }
}

void player_mvup(t_sok *sok)
{
    char **pos = sok->buffer;
    int x = sok->x;
    int y = sok->y;

    if ((pos[y - 1][x] == 'X' && pos[y - 2][x] == ' ') ||
        (pos[y - 1][x] == 'X' && pos[y - 2][x] == 'O')) {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y - 1][x] = 'P';
        pos[y - 2][x] = 'X';
        sok->y -= 1;
    } else if (pos[y - 1][x] == ' ' || pos[y - 1][x] == 'O') {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y - 1][x] = 'P';
        sok->y -= 1;
    }
}

void player_mvdown(t_sok *sok)
{
    char **pos = sok->buffer;
    int x = sok->x;
    int y = sok->y;

    if ((pos[y + 1][x] == 'X' && pos[y + 2][x] == ' ') ||
        (pos[y + 1][x] == 'X' && pos[y + 2][x] == 'O')) {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y + 1][x] = 'P';
        pos[y + 2][x] = 'X';
        sok->y += 1;
    } else if (pos[y + 1][x] == ' ' || pos[y + 1][x] == 'O') {
        pos[y][x] = (sok->initial[y][x] == 'O') ? 'O' : ' ';
        pos[y + 1][x] = 'P';
        sok->y += 1;
    }
}
