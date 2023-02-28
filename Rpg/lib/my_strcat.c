/*
** EPITECH PROJECT, 2021
** str cat
** File description:
** on cat une str
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *str1, char const *str2)
{
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);
    char *ret = NULL;
    int i = 0;

    ret = malloc(sizeof(char) * (lenstr2 + lenstr1 + 1));
    if (!ret)
        return NULL;
    for (int l = 0; l != lenstr1; l++)
        ret[l] = str1[l];
    for (i = 0; i != lenstr2; i++) {
        ret[lenstr1 + i] = str2[i];
    }
    ret[lenstr2 + lenstr1] = '\0';
    return ret;
}
