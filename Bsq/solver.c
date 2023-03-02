/*
** EPITECH PROJECT, 2021
** solver.c
** File description:
** solver functions
*/

#include "bsq.h"
#include "my.h"

void maximal_square_one(t_bsq *bsq)
{
    for (int rows = 0; rows < bsq->map_rows &&
        (bsq->sq_max == 0) && (bsq->map_cols == 1); rows++) {
        if (bsq->dp[rows][0]) {
            bsq->sq_max_row = rows;
            bsq->sq_max = 1;
        }
    }
    for (int cols = 0; cols < bsq->map_cols &&
        (bsq->sq_max == 0) && (bsq->map_rows == 1); cols++) {
        if (bsq->dp[0][cols]) {
            bsq->sq_max_col = cols;
            bsq->sq_max = 1;
        }
    }
}

void check_min_square(t_bsq *bsq)
{
    for (int c = 0; (c < bsq->map_cols) && (bsq->sq_max == 1); c++) {
        if (bsq->dp[0][c] == 1) {
            bsq->sq_max_col = c;
            bsq->sq_max_row = 0;
        }
    }
}

void maximal_square_check(t_bsq *bsq, int r, int c)
{
    if (bsq->map[r][c] == 1)
        bsq->dp[r][c] = min(bsq->dp[r-1][c], bsq->dp[r][c-1],
                            bsq->dp[r-1][c-1]) + 1;
    if (bsq->dp[r][c] > bsq->sq_max) {
        bsq->sq_max = bsq->dp[r][c];
        bsq->sq_max_col = c;
        bsq->sq_max_row = r;
    }
}

int maximal_square(t_bsq *bsq)
{
    init_dp(bsq);
    if ((bsq->map_cols == 1) || (bsq->map_rows == 1)) {
        maximal_square_one(bsq);
        return (0);
    }
    for (int r = 1; r < bsq->map_rows; r++)
        for (int c = 1; c < bsq->map_cols; c++)
            maximal_square_check(bsq, r, c);
    check_min_square(bsq);
    return (0);
}
