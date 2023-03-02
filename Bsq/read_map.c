/*
** EPITECH PROJECT, 2021
** read_map.c
** File description:
** function about the map
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "bsq.h"
#include "my.h"

int read_map(t_bsq *bsq, char *filename)
{
    int fd;
    struct stat filestat;

    if (stat(filename, &filestat) == -1)
        return (-1);
    if ((bsq->buffer = malloc(sizeof(char) * filestat.st_size + 1)) == NULL)
        return (-1);
    if ((fd = open(filename, O_RDONLY)) == -1)
        return (-1);
    if (read(fd, bsq->buffer, filestat.st_size) == -1)
        return (-1);
    if (close(fd) == -1)
        return (-1);
    bsq->buffer[filestat.st_size] = '\0';
    return (0);
}

int get_map_size(t_bsq *bsq)
{
    int i = 0;

    bsq->map_size = 0;
    bsq->map_cols = 0;
    bsq->map_rows = 0;
    while (bsq->buffer[i] != '\n') {
        if (bsq->buffer[i] >= '0' && bsq->buffer[i] <= '9')
            bsq->map_size = bsq->map_size * 10 + (bsq->buffer[i] - '0');
        else
            return (-1);
        i++;
    }
    bsq->map_index = ++i;
    while (bsq->buffer[i++] != '\n')
        bsq->map_cols++;
    return (0);
}

int check_map(t_bsq *bsq)
{
    int i = 0;
    int cols = 0;

    i = bsq->map_index;
    while (bsq->buffer[i]) {
        if ((bsq->buffer[i] == '\n') && (bsq->map_cols == cols)) {
            cols = 0;
            bsq->map_rows++;
        } else if ((bsq->buffer[i] == '.') || (bsq->buffer[i] == 'o')) {
            cols++;
        } else
            return (-1);
        i++;
    }
    if (bsq->map_rows != bsq->map_size)
        return (-1);
    return (0);
}

int init_struct(t_bsq *bsq)
{
    bsq->map = (int **) malloc(sizeof(int *) * (bsq->map_rows));
    bsq->dp = (int **) malloc(sizeof(int *) * (bsq->map_rows));
    for (int rows = 0; rows < bsq->map_rows; rows++) {
        bsq->map[rows] = malloc(sizeof(int) * (bsq->map_cols));
        bsq->dp[rows] = malloc(sizeof(int) * (bsq->map_cols));
    }
    return (0);
}

int load_map(t_bsq *bsq)
{
    int i = bsq->map_index;
    int cols = 0;
    int rows = 0;

    if (init_struct(bsq) != 0)
        return (-1);
    while (bsq->buffer[i]) {
        if (bsq->buffer[i] == '\n') {
            cols = 0;
            rows++;
        } else {
            bsq->map[rows][cols] = (bsq->buffer[i] == '.') ? 1 : 0;
            bsq->dp[rows][cols] = 0;
            cols++;
        }
        i++;
    }
    return (0);
}
