/*
** EPITECH PROJECT, 2021
** map_check.c
** File description:
** map check management
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "includes/my_lib.h"
#include "includes/navy.h"

int check_map_format(t_navy *navy)
{
    int i = 0;

    if (my_strlen(navy->buf) != 32)
        return -1;
    while (navy->buf[i]) {
        if (!((navy->buf[i] >= '1' && navy->buf[i] <= '8') ||
            (navy->buf[i] >= 'A' && navy->buf[i] <= 'H') ||
            (navy->buf[i] == ':') || (navy->buf[i] == '\n')))
            return -1;
        i++;
    }
    return 0;
}

int check_map_cons(t_navy *navy, int b)
{
    char *nbuf = navy->buf;
    int ship_len = nbuf[b*8] - '0';

    if ((nbuf[b*8] < '2' || nbuf[b*8] > '5') ||
        (nbuf[1+b*8] != ':' || nbuf[4+b*8] != ':') ||
        (nbuf[2+b*8] < 'A' || nbuf[2+b*8] > 'H') ||
        (nbuf[3+b*8] < '1' || nbuf[3+b*8] > '8') ||
        (nbuf[5+b*8] < 'A' || nbuf[5+b*8] > 'H') ||
        (nbuf[6+b*8] < '1' || nbuf[6+b*8] > '8') ||
        (nbuf[7+b*8] != '\n'))
        return -1;
    if ((nbuf[2+b*8] == nbuf[5+b*8]) &&
        ((nbuf[6+b*8] - nbuf[3+b*8]) == (ship_len - 1)))
        map_set_ship_v(navy, b);
    else if ((nbuf[3+b*8] == nbuf[6+b*8]) &&
        ((nbuf[5+b*8] - nbuf[2+b*8]) == (ship_len - 1)))
        map_set_ship_h(navy, b);
    else
        return -1;
    return 0;
}

void map_set_ship_v(t_navy *navy, int b)
{
    int shiplen = 0;
    char *nbuf = navy->buf;

    shiplen = nbuf[b*8] - '0';
    for (int i = 0; i < shiplen; i++)
        navy->my_map[nbuf[2+b*8] - 'A'][nbuf[3+b*8] - '1' + i] = '0' + shiplen;
}

void map_set_ship_h(t_navy *navy, int b)
{
    int shiplen = 0;
    char *nbuf = navy->buf;

    shiplen = nbuf[b*8] - '0';
    for (int i = 0; i < shiplen; i++)
        navy->my_map[nbuf[2+b*8]-'A' + i][nbuf[3+b*8] -'1'] = '0' + shiplen;
}

int check_map(t_navy *navy)
{
    if (check_map_format(navy) == -1)
        return -1;
    for (int b = 0; b < 4; b++) {
        if (check_map_cons(navy, b) == -1)
            return -1;
    }
    return 0;
}
