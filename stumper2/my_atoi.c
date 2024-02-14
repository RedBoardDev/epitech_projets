/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** my_atoi.c
*/

#include "my.h"

int my_atoi(char const *src)
{
    int buff = 0;

    for (int i = 0; src[i] != '\0'; ++i) {
        if (!isnum(src[i]))
            return (0);
        buff *= 10;
        buff += src[i] - '0';
    }
    return (buff);
}
