/*
** EPITECH PROJECT, 2021
** game_cases.c
** File description:
** Game Cases management
*/

#include <unistd.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

void init_player_1 (t_navy *navy)
{
    my_putstr("waiting for enemy connection...\n");
    wait_signal_usr2();
    my_putstr("\nenemy connected\n\n");
    kill(global_navy.enemy_pid, SIGUSR2);
    print_all_maps(navy, 0);
    navy->state = 3;
}

void init_player_2 (t_navy *navy)
{
    kill(global_navy.enemy_pid, SIGUSR2);
    wait_signal_usr2();
    my_putstr("successfully connected\n\n");
    navy->state = 5;
}

void get_user_attack (t_navy *navy)
{
    int len = 0;

    my_putstr("attack: ");
    len = read(0, navy->attack, 50);
    if (len > 3 || navy->attack[0] < 'A' || navy->attack[0] > 'H'
        || navy->attack[1] < '1' || navy->attack[1] > '8') {
        my_putstr("Wrong position\n");
        navy->state = 3;
    } else {
        navy->col = navy->attack[0] - 'A';
        navy->line = navy->attack[1] - '1';
        if (navy->enemy_map[navy->col][navy->line] == 'x' ||
            navy->enemy_map[navy->col][navy->line] == 'o') {
            my_putstr("Already played\n");
            navy->state = 3;
        } else {
            send_msg(navy->col, navy->line);
            navy->state = 4;
        }
    }
}

void reply_to_attack (t_navy *navy)
{
    int ans = 0;

    ans = receive_answer();
    if (ans == 1) {
        my_putchar('A' + navy->col);
        my_putchar('1' + navy->line);
        my_putstr(": missed\n\n");
        navy->enemy_map[navy->col][navy->line] = 'o';
    } else {
        my_putchar('A' + navy->col);
        my_putchar('1' + navy->line);
        my_putstr(": hit\n\n");
        navy->enemy_map[navy->col][navy->line] = 'x';
        navy->my_hit++;
    }
    navy->state = 5;
}

void get_enemy_attack (t_navy *navy)
{
    print_all_maps(navy, 2);
    my_putstr("waiting for enemy's attack...\n");
    receive_msg(&navy->col, &navy->line);
    if (navy->my_map[navy->col][navy->line] >= '2' &&
        navy->my_map[navy->col][navy->line] <= '5') {
        navy->enemy_hit++;
        navy->my_map[navy->col][navy->line] = 'x';
        my_putchar('A' + navy->col);
        my_putchar('1' + navy->line);
        my_putstr(": hit\n\n");
        kill(global_navy.enemy_pid, SIGUSR2);
    } else if (navy->my_map[navy->col][navy->line] == '.') {
        navy->my_map[navy->col][navy->line] = 'o';
        my_putchar('A' + navy->col);
        my_putchar('1' + navy->line);
        my_putstr(": missed\n\n");
        kill(global_navy.enemy_pid, SIGUSR1);
    }
    navy->state = 3;
    print_all_maps(navy, 1);
}
