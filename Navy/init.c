/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** init functions
*/

#include <unistd.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

int init_struct(t_navy *navy)
{
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                navy->my_map[i][j] = '.';
                navy->enemy_map[i][j] = '.';
        }
    }
    navy->enemy_hit = 0;
    navy->my_hit = 0;
    navy->state = 0;
    navy->col = 0;
    navy->line = 0;
    navy->player = 0;
    global_navy.num_sig1 = 0;
    global_navy.num_sig2 = 0;
    global_navy.enemy_pid = 0;
    global_navy.my_pid = 0;
    return 0;
}

int init_navy(t_navy *navy, int ac, char **av)
{
    if (init_signals() == -1)
        return -1;
    if (ac == 3) {
        global_navy.enemy_pid = my_getnbr(av[1]);
        navy->state = 2;
        navy->player = 2;
    } else {
        navy->state = 1;
        navy->player = 1;
    }
    return 0;
}

void show_my_pid(void)
{
    global_navy.my_pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(global_navy.my_pid);
    my_putchar('\n');
}
