/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** all the function and struct
*/

#ifndef BSQ_H_INCLUDED
    #define BSQ_H_INCLUDED

typedef struct s_bsq {
    char *buffer;
    int map_index;
    int map_size;
    int **map;
    int **dp;
    int map_cols;
    int map_rows;
    int sq_max;
    int sq_max_row;
    int sq_max_col;
} t_bsq;

int read_map(t_bsq *bsq, char *filename);
int check_map(t_bsq *bsq);
int load_map(t_bsq *bsq);
int min(int a, int b, int c);
int maximal_square(t_bsq *bsq);
void maximal_square_one(t_bsq *bsq);
void maximal_square_check(t_bsq *bsq, int r, int c);
void show_square(t_bsq *bsq);
void show_char(t_bsq *bsq, int r, int c);
void check_min_square(t_bsq *bsq);
void init_dp(t_bsq *bsq);
int init_struct(t_bsq *bsq);
int get_map_size(t_bsq *bsq);

#endif
