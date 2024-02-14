/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i;
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);

    for (int i = 0; i < my_strlen(src); ++i)
        str[i] = src[i];
    return (str);
}
