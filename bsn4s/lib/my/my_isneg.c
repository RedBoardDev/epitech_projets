/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** my_isneg.c
*/

#include "my.h"

int my_isneg(int n)
{
    if (n > 0 || !n) {
        my_putchar(80);
    } else
        my_putchar(78);
    return (0);
}
