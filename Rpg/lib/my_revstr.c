/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** revstr
*/

#include <stdlib.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char *rem = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int l = 0, s = my_strlen(str) - 1; str[l] != '\0'; l++, s--)
        rem[l] = str[s];
    rem[my_strlen(str)] = '\0';
    free(str);
    return rem;
}
