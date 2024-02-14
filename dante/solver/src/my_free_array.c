/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** my_free_array.c
*/

#include "../include/solver.h"

void my_freearray(char **array)
{
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
}
