/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator.h
*/

#ifndef GENERATOR_H
    #define GENERATOR_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include "struct.h"

void generator(vector_t size_tot, bool perfect);
char **make_base_maze(vector_t size_tot);
int my_rand(int min, int max);
void print_word_array(char **maze, vector_t size_tot);
void free_word_array(char **maze);
void find_cul_de_sac(char **maze, vector_t size_tot);
void make_cell(char **maze, vector_t size_tot, int i, int j);

#endif
