/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** my_is.c
*/

#include "my.h"

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}