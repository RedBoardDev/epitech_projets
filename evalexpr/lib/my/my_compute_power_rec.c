/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** Returns the first argument raised to the power p with a recurstion.
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int result;

    result = nb;
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p > 0) {
        --p;
        result = result * my_compute_power_rec(nb, p);
    }
    return (result);
}
