/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map management
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

int read_map(t_navy *navy, char *filename)
{
    int fd;
    struct stat filestat;

    if (stat(filename, &filestat) == -1)
        return (-1);
    if ((navy->buf = malloc(sizeof(char) * filestat.st_size + 1)) == NULL)
        return (-1);
    if ((fd = open(filename, O_RDONLY)) == -1)
        return (-1);
    if (read(fd, navy->buf, filestat.st_size) == -1)
        return (-1);
    if (close(fd) == -1)
        return (-1);
    navy->buf[filestat.st_size] = '\0';
    return (0);
}

void print_map(const char map[8][8])
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int l = 0; l < 8; l++) {
        my_putchar('0' + l + 1);
        my_putchar('|');
        for (int c = 0; c < 8; c++) {
            my_putchar(map[c][l]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void print_all_maps(t_navy *navy, int player)
{
    if ((player == 0) || (navy->player == player)) {
        my_putstr("my positions:\n");
        print_map(navy->my_map);
        my_putstr("\nenemy's positions:\n");
        print_map(navy->enemy_map);
        my_putchar('\n');
    }
}
