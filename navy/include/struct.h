/*
** EPITECH PROJECT, 2021
** navy
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <stdbool.h>

typedef struct players_s {
    char *filepath;
    char map[8][8];
} players_t;

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct game_s {
    int player;
    int my_pid;
    int enemy_pid;
    int tour;
    bool win;
} game_t;

#endif
