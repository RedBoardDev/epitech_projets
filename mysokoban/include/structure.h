/*
** EPITECH PROJECT, 2021
** PROJET-thomas.ott
** File description:
** structure.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct vector_s {
    int x;
    int y;
}vector_t;

typedef struct maps_s {
    vector_t pos;
    vector_t player_start;
    vector_t size_map;
    char **map;
    char **save_map;
    int count_storage;
}maps_t;

#endif
