/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-Cworkshoplib-martin.d-herouville
** File description:
** my_printarray.c
*/

#include "my.h"

void printarray(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        my_put_nbr(arr[i]);
        if (i < size - 1) {
            my_putchar(44);
            my_putchar(' ');
        }
    }
    my_putchar('\n');
}
