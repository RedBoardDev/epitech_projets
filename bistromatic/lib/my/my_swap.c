/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** Swaps the content of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
