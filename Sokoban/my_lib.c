/*
** EPITECH PROJECT, 2021
** my_lib.c
** File description:
** Standard my_lib functions
*/

#include <unistd.h>
#include "includes/my_lib.h"

int my_putchar(char c)
{
    write(1 , &c, 1);
    return 1;
}

int my_put_nbr(int nb)
{
    if (nb > 9)
        my_put_nbr(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}

void my_putstr(const char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        my_putchar(str[i]);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
