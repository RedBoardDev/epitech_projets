/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** structure.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct vector_s {
    int x;
    int y;
}vector_t;

typedef struct finder_s {
    int direction;
    vector_t pos_finder;
}finder_t;

typedef struct solver_s {
    char **map;
    int **map_i;
    int height;
    int widht;
    finder_t finder;
}solver_t;

#endif
