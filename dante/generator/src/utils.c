/*
** EPITECH PROJECT, 2021
** dante
** File description:
** utils.c
*/

#include "../include/generator.h"
#include "../include/struct.h"

int my_rand(int min, int max)
{
    return (min + rand() % ((max + 1) - min));
}

void print_word_array(char **maze, vector_t size_tot)
{
    for (int i = 0; i < size_tot.x; ++i) {
        for (int j = 0; j < size_tot.y; ++j)
            printf("%c", maze[i][j]);
        if (i < size_tot.x - 1)
            printf("\n");
    }
}

void free_word_array(char **maze)
{
    for (int i = 0; maze[i] != NULL; ++i)
        free(maze[i]);
    free(maze);
}
