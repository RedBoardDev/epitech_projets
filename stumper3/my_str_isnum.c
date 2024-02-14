/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        ++i;
    for (; str[i] != '\0'; ++i) {
        if ((int) str[i] < 48 || (int) str[i] > 57)
            return 0;
    }
    return 1;
}
