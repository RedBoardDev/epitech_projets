/*
** EPITECH PROJECT, 2021
** MY_SWAP
** File description:
** Swap tow integers
*/

#include "my.h"

int my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return (0);
}
