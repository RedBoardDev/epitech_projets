/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** my_atoi.c
*/

#include "my.h"

int isnum_atoi(char c/*, char *arg2*/)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_atoi(char const *src)
{
    int dest = 0;

    for (int i = 0; src[i] != '\0'; ++i) {
        if (!isnum_atoi(src[i])) {
            my_putstr("Invalid argument\n");
            exit (84);
        }
        dest *= 10;
        dest += src[i] - 48;
    }
    return (dest);
}

/*int main(int ac, char **av)
{
    my_put_nbr(my_atoi(av[1]));
    return (0);
}*/
