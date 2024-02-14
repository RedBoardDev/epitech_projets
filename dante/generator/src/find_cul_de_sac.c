/*
** EPITECH PROJECT, 2021
** dante
** File description:
** find_cul_de_sac.c
*/

#include "../include/generator.h"
#include "../include/struct.h"
#include <unistd.h>

int count_x_around(char **maze, vector_t size_tot, int i, int j)
{
    int count = 0;

    if (i > 0 && maze[i - 1][j] == 'X')
        ++count;
    if (i < size_tot.x - 1 && maze[i + 1][j] == 'X')
        ++count;
    if (j > 0 && maze[i][j - 1] == 'X')
        ++count;
    if (i < size_tot.y - 1 && maze[i][j + 1] == 'X')
        ++count;
    if (i > 0 && j > 0 && maze[i - 1][j - 1] == 'X')
        ++count;
    if (i < size_tot.x - 1 && j > 0 && maze[i + 1][j - 1] == 'X')
        ++count;
    if (i > 0 && j < size_tot.y - 1 && maze[i - 1][j + 1] == 'X')
        ++count;
    if (i < size_tot.y - 1 && j < size_tot.y - 1 && maze[i + 1][j + 1] == 'X')
        ++count;
    return (count);
}

void fill_with_x_around(char **maze, vector_t size_tot, int i, int j)
{
    if (i > 0)
        maze[i - 1][j] = 'X';
    if (i < size_tot.x - 1)
        maze[i + 1][j] = 'X';
    if (j > 0)
        maze[i][j - 1] = 'X';
    if (i < size_tot.y - 1)
        maze[i][j + 1] = 'X';
    if (i > 0 && j > 0)
        maze[i - 1][j - 1] = 'X';
    if (i < size_tot.x - 1 && j > 0)
        maze[i + 1][j - 1] = 'X';
    if (i > 0 && j < size_tot.y - 1)
        maze[i - 1][j + 1] = 'X';
    if (i < size_tot.y - 1 && j < size_tot.y - 1)
        maze[i + 1][j + 1] = 'X';
}

bool check_cell_find(char **maze, vector_t size_tot, int i, int j)
{
    if (maze[i][j] == 'X')
        return (true);
    if (count_x_around(maze, size_tot, i, j) == 7) {
        fill_with_x_around(maze, size_tot, i, j);
        return (false);
    } else
        return (true);
}

void find_cul_de_sac(char **maze, vector_t size_tot)
{
    bool check = true;

    for (int i = 0; check && i < size_tot.x; ++i)
        for (int j = 0; check && j < size_tot.y; ++j)
            check = check_cell_find(maze, size_tot, i, j);
}
