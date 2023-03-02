/*
** EPITECH PROJECT, 2021
** show_square.c
** File description:
** function to display, show square
*/

#include "bsq.h"
#include "my.h"

void show_char(t_bsq *bsq, int r, int c)
{
    if (bsq->map[r][c] == 1) {
        if (((r > bsq->sq_max_row - bsq->sq_max) &&
            (r <= bsq->sq_max_row)) &&
            ((c > bsq->sq_max_col - bsq->sq_max) &&
            (c <= bsq->sq_max_col))) {
            my_putchar('x');
        } else
            my_putchar('.');
    } else
        my_putchar('o');
}

void show_square(t_bsq *bsq)
{
    for (int r = 0; r < bsq->map_rows; r++) {
        for (int c = 0; c < bsq->map_cols; c++)
            show_char(bsq, r, c);
        my_putchar('\n');
    }
}
