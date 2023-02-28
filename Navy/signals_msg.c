/*
** EPITECH PROJECT, 2021
** signals_msg.c
** File description:
** signal Messages management
*/

#include <unistd.h>
#include <signal.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

void send_msg(int col, int line)
{
    for (int i = 0; i < col; i++) {
        kill(global_navy.enemy_pid, SIGUSR1);
        usleep(200);
    }
    kill(global_navy.enemy_pid, SIGUSR2);
    usleep(200);
    for (int i = 0; i < line; i++) {
        kill(global_navy.enemy_pid, SIGUSR1);
        usleep(200);
    }
    kill(global_navy.enemy_pid, SIGUSR2);
}

void receive_msg(int *col, int *line)
{
    *col = wait_signal_usr2();
    *line = wait_signal_usr2();
}

int receive_answer(void)
{
    while (global_navy.num_sig2 == 0 && global_navy.num_sig1 == 0)
        pause();
    if (global_navy.num_sig1 != 0) {
        global_navy.num_sig1 = 0;
        return 1;
    } else {
        global_navy.num_sig2 = 0;
        return 2;
    }
}
