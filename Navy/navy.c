/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** main function of navy
*/

#include "includes/my_lib.h"
#include "includes/navy.h"

t_global_navy global_navy;

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the positions ");
    my_putstr("of the ships.\n");
}

int main(int ac, char **av)
{
    t_navy navy;

    if ((ac == 2) && (av[1][0] == '-') && (av[1][1] == 'h')) {
        print_help();
        return 0;
    } else if ((ac == 1) || (ac > 3)) {
        my_putstr("Usage: navy [-h]\n");
        return 0;
    }
    init_struct(&navy);
    show_my_pid();
    if (read_map(&navy, av[ac - 1]) == -1)
        return 84;
    if (check_map(&navy) == -1)
        return 84;
    if (init_navy(&navy, ac, av) == -1)
        return 84;
    if (play_game(&navy) == -1)
        return 84;
    return 0;
}
