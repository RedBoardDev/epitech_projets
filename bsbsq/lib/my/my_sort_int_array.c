/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** my_sort_int_array.c
*/

#include "my.h"

int yes_swap(int j, int *array)
{
    if (array[j] > array[j + 1])
        my_swap(&array[j], &array[j+1]);
}

void my_sort_int_array(int *array, int size)
{
    int i = 1;
    int j = 0;

    for (; array[i] != '\0'; ++i, ++j) {
        for (j = 0; j < size - i; ++j)
            yes_swap(j, array);
    }
}
