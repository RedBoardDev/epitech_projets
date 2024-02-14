/*
** EPITECH PROJECT, 2021
** dante
** File description:
** make_base_maze.c
*/

#include "../include/generator.h"
#include "../include/struct.h"

char **make_base_maze(vector_t size_tot)
{
    char **maze = malloc(sizeof(char *) * (size_tot.x + 1));

    for (int i = 0; i < size_tot.x; ++i) {
        maze[i] = malloc(sizeof(char) * (size_tot.y + 1));
        for (int j = 0; j < size_tot.y; ++j)
            maze[i][j] = 'X';
        maze[i][size_tot.y] = '\0';
    }
    maze[size_tot.x] = NULL;
    return (maze);
}
