/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_sort_int_array.c
*/

#include "my.h"

int testiff(int *array, int size)
{
    int count = 0;
    for (int j = 0; j < size - 1; ++j) {
        if (array[j] <= array[j + 1] && j < size - 1)
            ++count;
    }
    return (count);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int k = 0;

    while (i < size - 1) {
        if (array[k] > array[k + 1] && k < size - 1) {
            my_swap(&array[k], &array[k + 1]);
        }
        ++k;
        if (k == size)
            k = 0;
        i = testiff(array, size);
    }
    printarray(array, size);
}

/*int main(void)
{
    int array[8] = {4, -0, 45, -56, 87979, -1, 5, 456};

    printarray(array, 8);
    my_sort_int_array(array, 8);
    return (0);
}*/
