/*
** EPITECH PROJECT, 2021
** my_sokoban.h
** File description:
** structure
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef MY_SOKOBAN_H_INCLUDED
    #define MY_SOKOBAN_H_INCLUDED

typedef struct s_sok {
    char **buffer;
    int size;
    int col;
    int row;
    char **initial;
    int x;
    int y;
    int num_boxes;
    int num_boxes_ok;
    int num_stores;
    int end;
} t_sok;

int init_map(t_sok *sok, char *file);
void draw_map(t_sok *sok);
void get_map_size(t_sok *sok);
void init_struct(t_sok *sok);
int check_map(t_sok *sok, char *map);
void play_game(t_sok *sok);
void free_game(t_sok *sok);
void reset_game(t_sok *sok);
char **my_str_to_word_array(char *str, char *sep);
void move_player(t_sok *sok, int key);
void player_mvleft(t_sok *sok);
void player_mvright(t_sok *sok);
void player_mvup(t_sok *sok);
void player_mvdown(t_sok *sok);
void get_player_pos(t_sok *sok);
int check_end(t_sok *sok);
int is_end(t_sok *sok, int y, int x);

#endif
