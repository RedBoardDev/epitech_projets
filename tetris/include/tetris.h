/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** tetris.h
*/

#ifndef TETRIS_H
    #define TETRIS_H

    #include "../include/my.h"
    #include "../include/struct.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <getopt.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>
    #define FOLDER "tetriminos"

enum color_sets_others {
    FORE_WHITE = 100,
    NBR_COLOR_SETS_TOT
};

int print_help(void);
int debug(tetris_t tetris);
int tetris_fc(tetris_t *tetris);
args_t get_args(int ac, char **av);
tetrimino_t *init_open_folder_maps(void);
tetrimino_t open_file(char *file_name);
int get_random_piece(tetris_t *tetris);
int custom_strlen(char const *str);
void draw_one_piece(tetrimino_t tetrimino, int x, int y, int rotation);

// init
void init_colors(void);
void inits_ncurses(void);

//draw
void draw_all(tetris_t *tetris);
void draw_interface(tetris_t *tet);

// utils
void my_exit(int score, int return_value);
int my_rand(int min, int max);

// backup
int get_backup(void);
void put_backup(int nbr);

#endif
