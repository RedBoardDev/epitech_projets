/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strcat_2(char const *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest) + my_strlen(src) + 2;
    char *final_str = malloc(sizeof(char) * len);

    for (; dest[i] != '\0'; ++i)
        final_str[i] = dest[i];

    final_str[i++] = '/';
    for (int j = 0; src[j] != '\0'; ++i, ++j)
        final_str[i] = src[j];
    final_str[i] = '\0';
    return (final_str);
}
