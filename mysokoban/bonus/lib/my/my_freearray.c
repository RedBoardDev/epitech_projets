/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** my_freearray.c
*/

#include "my.h"

void my_freearray(char **array) {
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
}
