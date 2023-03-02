/*
** EPITECH PROJECT, 2021
** bsq.c
** File description:
** main function
*/

#include "bsq.h"
#include "my.h"

int main(int ac, char **av)
{
    t_bsq bsq;

    if (ac != 2) {
        my_putstr("Usage: bsq map\n");
        return (84);
    } else {
        if (read_map(&bsq, av[1]) != 0)
            return (84);
        if (get_map_size(&bsq) != 0)
            return (84);
        if (check_map(&bsq) != 0)
            return (84);
        if (load_map(&bsq) != 0)
            return (84);
        maximal_square(&bsq);
        show_square(&bsq);
    }
    return (0);
}
