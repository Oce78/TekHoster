/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Andrea Mancion
*/

int my_putchar(char);

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return (0);
}
