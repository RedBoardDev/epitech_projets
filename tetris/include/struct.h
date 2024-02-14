/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <stdbool.h>
     #include <time.h>

typedef struct {
    int x;
    int y;
} vector_t;

typedef struct {
    int help;
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    vector_t map_size;
    int without_next;
    int debug;
} args_t;

typedef struct {
    bool active;
    char **piece;
    char *name;
    vector_t size;
    int color;
    int size_struct;
} tetrimino_t;

typedef struct {
    int speed;
    int rotation;
    int level;
    int lines;
    int score;
    int high_score;
    time_t t_begin;
} info_t;

typedef struct {
    tetrimino_t *tetriminos;
    args_t args;
    int piece;
    vector_t pos_piece;
    int next_piece;
    info_t info;
} tetris_t;

#endif
