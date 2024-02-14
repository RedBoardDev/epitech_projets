/*
** EPITECH PROJECT, 2022
** perso
** File description:
** my_put
*/

#include "../include/corewar.h"

int my_str_is_int(char *str)
{
    int tmp = 0;

    if (str[0] == '\0')
        return -1;
    for (int n = 0; str[n] != '\0'; ++n) {
        if ((str[n] < '0') && (str[n] > '9'))
            return -1;
        tmp = (tmp * 10) + (str[n] - 48);
    }
    return (tmp);
}

int my_strcmp(char *str, char *cmp)
{
    int i = 0;

    for (; str[i] != '\0'; ++i)
        if ((str[i] != cmp[i]) || (cmp[i] == '\0'))
            return 1;
    if (str[i] != cmp[i])
        return 1;
    return 0;
}

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    write (1, str, i);
}
