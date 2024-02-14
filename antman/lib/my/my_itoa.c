/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** my_itoa.c
*/

#include "my.h"

char *my_itoa(int nb)
{
    int len = 0;
    char *str;
    int tmp = 0;

    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp /= 10;
        ++len;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}
