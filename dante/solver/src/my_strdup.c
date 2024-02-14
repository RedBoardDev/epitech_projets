/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <string.h>

int **my_arraydup(char **src)
{
    int i = 0;
    int r = 0;
    int **str = NULL;

    for (; src[i] != NULL; ++i);
    str = malloc(sizeof(int *) * (i + 1));
    for (int y = 0; y < i; ++y) {
        str[y] = malloc(sizeof(int)* strlen(src[y]));
        for (int x = 0; x < strlen(src[y]); x++)
            str[y][x] = src[y][x] == 'X' ? -1 : 0;
    }
    return (str);
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * strlen(src) + 1);

    for (; i < strlen(src); ++i)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
