/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** concat.c
*/

#include "concat.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(const char *str1, const char *str2)
{
    char *res;
    int dest_len = strlen(str1);
    int src_len = strlen(str2);
    int i;

    res = malloc(sizeof(char) * (dest_len + src_len) + 1);

    for (i = 0; str1[i] != '\0'; ++i)
        res[i] = str1[i];
    for (i = 0 ; str2[i] != '\0' ; i++)
        res[dest_len + i] = str2[i];
    res[dest_len + i] = '\0';
    return res;
}

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = my_strcat(str1, str2);
}

void concat_struct(concat_t *str)
{
    str->res = my_strcat(str->str1, str->str2);
}
