/*
** EPITECH PROJECT, 2021
** my_sokoban.c
** File description:
** main and help of my_sokoban
*/

#include <stdlib.h>
#include "includes/my_lib.h"
#include "includes/my_sokoban.h"

static int print_help (void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map,");
    my_putstr(" containing ‘#’ for walls,\n");
    my_putstr("         ‘P’ for the player, ‘X’ for boxes and ‘O’ for");
    my_putstr(" storage locations.\n");
    return 0;
}

int main(int ac, char **av)
{
    t_sok sok;

    if ((ac == 2) && (av[1][0] == '-') && (av[1][1] == 'h')) {
        return print_help();
    } else if (ac != 2) {
        my_putstr("Usage: my_sokoban [-h]\n");
        return 84;
    }
    init_struct(&sok);
    if (init_map(&sok, av[1]) == -1)
        return 84;
    play_game(&sok);
    free_game(&sok);
    if (sok.end == 2)
        return 1;
    return 0;
}
