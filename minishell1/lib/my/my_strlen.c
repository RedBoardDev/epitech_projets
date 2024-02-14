/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** returns the number of characters found
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len]; ++len);
    return (len);
}
