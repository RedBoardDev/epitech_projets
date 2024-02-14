/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char **my_arraydup(char **src)
{
    int i = 0;
    int r = 0;
    char **str = NULL;

    for (; src[i] != NULL; ++i);
    str = malloc(sizeof(char *) * (i + 1));
    for (int y = 0; y < i; ++y) {
        str[y] = my_strdup(src[y]);
    }
    str[i] = NULL;
    return (str);
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
