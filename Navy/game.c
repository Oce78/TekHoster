/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game management
*/

#include "includes/my_lib.h"
#include "includes/navy.h"

int play_game(t_navy *navy)
{
    while (navy->enemy_hit != 14 && navy->my_hit != 14) {
        play_game_switch(navy);
    }
    print_result(navy);
    return 0;
}

void play_game_switch(t_navy *navy)
{
    switch (navy->state) {
        case 1:
            init_player_1(navy);
            break;
        case 2:
            init_player_2(navy);
            break;
        case 3:
            get_user_attack(navy);
            break;
        case 4:
            reply_to_attack(navy);
            break;
        case 5:
            get_enemy_attack(navy);
            break;
    }
}

void print_result(t_navy *navy)
{
    print_all_maps(navy, 0);
    if (navy->my_hit == 14)
        my_putstr("\nI won\n");
    else if (navy->enemy_hit == 14)
        my_putstr("\nEnemy won\n");
}
