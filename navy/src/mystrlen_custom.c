/*
** EPITECH PROJECT, 2021
** navy
** File description:
** mystrlen_custom.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

int mystrlen_custom(char *a)
{
    int count = 0;

    for (int i = 0; a[i] != '\0'; ++i)
        if (isletter(a[i]) || isnum(a[i]))
            ++count;
    return (count);
}
