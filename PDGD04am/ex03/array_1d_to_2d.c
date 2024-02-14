/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** array_1d_to_2d.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(sizeof(int **) * height);
    for (size_t i = 0, f = 0; i < height; ++i) {
        (*res)[i] = malloc(sizeof(int *) * width);
        for (size_t r = 0; r < width; ++r, ++f) {
            (*res)[i][r] = array[f];
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (size_t i = 0; i < height; ++i) {
        free(array[i]);
    }
    free(array);
    width = width;
}
