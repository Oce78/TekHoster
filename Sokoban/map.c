/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map of my_sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/my_lib.h"
#include "includes/my_sokoban.h"

int get_size(char *file)
{
    struct stat sb;

    stat(file, &sb);
    return (sb.st_size);
}

int check_map(t_sok *sok, char *map)
{
    int num_p = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] != 'P' && map[i] != 'X' && map[i] != 'O' &&
            map[i] != ' ' && map[i] != '#' && map[i] != '\n')
            return -1;
        if (map[i] == 'X')
            sok->num_boxes++;
        if (map[i] == 'O')
            sok->num_stores++;
        if (map[i] == 'P')
            num_p++;
    }
    if ((num_p != 1) || (sok->num_boxes > sok->num_stores) ||
        (sok->num_stores == 0))
        return -1;
    return 0;
}

int read_map(t_sok *sok, char *file)
{
    int fd;
    int size = 0;
    char *str = NULL;

    if ((fd = open(file, O_RDONLY)) == -1)
        return -1;
    size = get_size(file);
    str = malloc(sizeof(char) * (size + 1));
    read(fd, str, size);
    str[size] = '\0';
    if (check_map(sok, str) == -1)
        return -1;
    sok->buffer = my_str_to_word_array(str, "\n");
    sok->initial = my_str_to_word_array(str, "\n");
    if (str == NULL || sok->buffer == NULL)
        return -1;
    get_map_size(sok);
    free(str);
    close(fd);
    return 0;
}

int init_map(t_sok *sok, char *file)
{
    int size = 0;

    sok->buffer = NULL;
    if ((read_map(sok, file)) == -1)
        return -1;
    get_player_pos(sok);
    for (; sok->buffer[size] != NULL; size++);
    sok->size = size;
    return 0;
}

void get_map_size(t_sok *sok)
{
    int x = 0;
    int y = 0;

    for (y = 0; sok->buffer[y] != NULL; y++) {
        for (x = 0; sok->buffer[y][x] != '\0'; x++);
        sok->col = (x > sok->col) ? x : sok->col;
    }
    sok->row = y;
}
