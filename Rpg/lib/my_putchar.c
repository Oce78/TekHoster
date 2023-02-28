/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Permet d'afficher les caractère
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
