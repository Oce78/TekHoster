/*
** EPITECH PROJECT, 2021
** bsq_utils.c
** File description:
** bsq utils functions
*/

#include "bsq.h"
#include "my.h"

int min(int a, int b, int c)
{
    int min;

    if ((a < b) && (a < c))
        min = a;
    else if (b < c)
        min = b;
    else
        min = c;
    return min;
}

void init_dp(t_bsq *bsq)
{
    bsq->sq_max = 0;
    bsq->sq_max_row = 0;
    bsq->sq_max_col = 0;
    for (int rows = 0; rows < bsq->map_rows; rows++)
        bsq->dp[rows][0] = bsq->map[rows][0];
    for (int cols = 0; cols < bsq->map_cols; cols++)
        bsq->dp[0][cols] = bsq->map[0][cols];
}
