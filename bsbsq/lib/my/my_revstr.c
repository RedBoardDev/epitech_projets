/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** MY_REVSTR
*/

#include "my.h"

char *my_revstr(char *str)
{
    int iLen = 0;
    int i = 0;

    char *strReverse[my_strlen(str)];
    iLen = my_strlen(str) - 1;
    while (i < iLen) {
        *strReverse[iLen] = str[i];
        str[i] = str[iLen];
        str[iLen] = *strReverse[i];
        ++i;
        --iLen;
    }
    return str;
}
