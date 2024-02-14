/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *dest_ui = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1));

    for (; dest[i] != '\0'; ++i)
        dest_ui[i] = dest[i];
    for (int j = 0; src[j] != '\0' ; ++i, ++j)
        dest_ui[i] = src[j];
    dest_ui[i] = '\0';
    return (dest_ui);
}
