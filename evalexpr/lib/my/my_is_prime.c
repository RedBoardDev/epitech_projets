/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** Returns 1 if the number is prime and 0 if not.
*/

#include "my.h"

int my_is_integer(float val)
{
    int test;

    test = (int)val;
    if (val == test) {
        return (1);
    } else {
        return (0);
    }
}

int my_is_prime(int nb)
{
    float i;

    if (nb <= 1) {
        return (0);
    }

    for (i = 2; i < nb; ++i) {
        if (my_is_integer(nb / i) == 1) {
            return (0);
        }
    }
    return (1);
}
