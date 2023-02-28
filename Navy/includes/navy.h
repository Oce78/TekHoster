/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy structures
*/

#include <signal.h>

#ifndef NAVY_H_INCLUDED
    #define NAVY_H_INCLUDED

typedef struct s_navy {
    char *buf;
    char my_map[8][8];
    char enemy_map[8][8];
    char attack[50];
    int enemy_hit;
    int my_hit;
    int col;
    int line;
    int state;
    int player;
} t_navy;

typedef struct s_global_navy {
    int my_pid;
    int enemy_pid;
    volatile sig_atomic_t num_sig1;
    volatile sig_atomic_t num_sig1_saved;
    volatile sig_atomic_t num_sig2;
} t_global_navy;

extern t_global_navy global_navy;

// init.c
int init_struct(t_navy *navy);
int init_navy(t_navy *navy, int ac, char **av);
void show_my_pid(void);
// navy.c (Main)
void print_help(void);
// map.c
int read_map(t_navy *navy, char *filename);
void print_map(const char map[8][8]);
void print_all_maps(t_navy *navy, int player);
// map_check.c
int check_map(t_navy *navy);
int check_map_format(t_navy *navy);
int check_map_cons(t_navy *navy, int b);
void map_set_ship_v(t_navy *navy, int b);
void map_set_ship_h(t_navy *navy, int b);
// signals.c
int init_signals(void);
void handle_signal(int signal, siginfo_t *si, void *context);
int wait_signal_usr2 (void);
// signals_msg.c
void send_msg(int col, int line);
void receive_msg(int *col, int *line);
int receive_answer(void);
// game.c
int play_game(t_navy *navy);
void play_game_switch(t_navy *navy);
void print_result(t_navy *navy);
// game_cases.c
void init_player_1(t_navy *navy);
void init_player_2(t_navy *navy);
void get_user_attack(t_navy *navy);
void reply_to_attack(t_navy *navy);
void get_enemy_attack(t_navy *navy);

#endif
