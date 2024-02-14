/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** mul_div.c
*/

#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
    *mul = a * b;
}

void mul_div_short(int *a, int *b)
{
    int r = *a * *b;
    int f = *b == 0 ? 42 : *a / *b;

    *a = r;
    *b = f;
}
