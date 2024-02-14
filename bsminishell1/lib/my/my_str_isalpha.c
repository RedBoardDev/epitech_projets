/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** my_str_isalpha.c
*/

#include "my.h"
#include <stddef.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' &&  str[i] <= 'z')
            i = i + 1;
        else
            return (0);
    return (1);
}
