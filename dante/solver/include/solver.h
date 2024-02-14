/*
** EPITECH PROJECT, 2021
** dante
** File description:
** solver.h
*/

#ifndef SOLVER_H
    #define SOLVER_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "structure.h"
    #define CHECK_FIND_PATH(x) list[x] != 0 && list[x] != -1
enum direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

int solver(char *filepath);
void my_freearray(char **array);
int init_finder(finder_t *finder);
void search_solution(solver_t *solver);
int **my_arraydup(char **src, int w, int h);
int set_maps(char *filepath, solver_t *solver);
char **my_str_to_word_array(char const *str);

//move finder
int choose_case(solver_t *solver);
int finder_north(solver_t *solver);
int finder_west(solver_t *solver);
int finder_south(solver_t *solver);
int finder_east(solver_t *solver);

//maps
void set_number_case(solver_t *solver);
void find_faster_path(solver_t *solver);
void final_print(int found_path, solver_t *solver);

#endif
