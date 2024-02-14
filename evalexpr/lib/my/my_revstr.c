/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int o;
    int h;
    char temp;

    o = my_strlen(str) - 1;
    h = 0;
    while (o > h) {
        temp = str[h];
        str[h] = str[o];
        str[o] = temp;
        ++h;
        --o;
    }
}
