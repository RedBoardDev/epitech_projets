/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return len;
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);

    for (; i < my_strlen(src); ++i)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
