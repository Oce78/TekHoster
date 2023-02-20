/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** mapp of my_sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/my_lib.h"
#include "includes/my_sokoban.h"

void play_game(t_sok *sok)
{
    int key = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (!check_end(sok)) {
        clear();
        draw_map(sok);
        key = getch();
        if (key == 27)
            break;
        if (key == 32)
            reset_game(sok);
        move_player(sok, key);
        refresh();
    }
    draw_map(sok);
    refresh();
    endwin();
}

void draw_map(t_sok *sok)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);
    if (row < sok->row || col < sok->col) {
        mvprintw((row - 1) / 2, (col - 16) / 2, "window too small");
    } else {
        for (int i = 0; sok->buffer[i] != NULL; i++)
            mvprintw(i, 0, sok->buffer[i]);
    }
}

void reset_game(t_sok *sok)
{
    for (int y = 0; sok->buffer[y] != NULL; y++)
        for (int x = 0; sok->buffer[y][x] != '\0'; x++)
            sok->buffer[y][x] = sok->initial[y][x];
    get_player_pos(sok);
}

void free_game(t_sok *sok)
{
    for (int i = 0; sok->buffer[i]; i++)
        free(sok->buffer[i]);
    free(sok->buffer);
    for (int i = 0; sok->initial[i]; i++)
        free(sok->initial[i]);
    free(sok->initial);
}
