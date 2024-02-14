/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** Displays either N if negative, or P if positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    char N = 78;
    char P = 80;

    if (n < 0) {
        my_putchar(N);
    } else {
        my_putchar(P);
    }
    return (0);
}
