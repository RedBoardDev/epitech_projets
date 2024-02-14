/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** my_strdup.c
*/

#include <stddef.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *mall = malloc(sizeof(char) * (len + 1));

    if (mall == NULL)
        return NULL;
    mall = my_strcpy(mall, src);
    mall[len] = '\0';
    return mall;
}
