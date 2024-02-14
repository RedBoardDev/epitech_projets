/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** Returns the square root of the number given as argument.
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i;

    i = 0;
    for (i = 0; nb >= i * i; ++i) {
        if (nb == i * i) {
            return (i);
        }
    }
    return (0);
}
