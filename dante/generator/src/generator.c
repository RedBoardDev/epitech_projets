/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator.c
*/

#include "../include/generator.h"
#include "../include/struct.h"
#include <unistd.h>

void make_row_simple(char **maze, vector_t size_tot, int i, bool perfect)
{
    int random = my_rand(0, 1);

    if (i % 2)
        for (int j = 0; j < size_tot.y; ++j)
            maze[i][j] = '*';
    else {
        maze[i][my_rand(0, size_tot.y - 1)] = '*';
        if (!perfect)
            maze[i][my_rand(0, size_tot.y - 1)] = '*';
    }
}

void simple_gen(vector_t size_tot, char **maze, bool perfect)
{
    for (int i = 0; i < size_tot.x; ++i)
        make_row_simple(maze, size_tot, i, perfect);
}

void complex_gen(vector_t size_tot, char **maze)
{
    for (int i = 0; i < size_tot.x; i += 2)
        for (int j = 0; j < size_tot.y; j += 2)
            make_cell(maze, size_tot, i, j);
}

void remove_borders(char **maze, vector_t size_tot)
{
    if (size_tot.x < 3 || size_tot.y < 3)
        return;
    for (int i = 0; i < size_tot.x; ++i)
        if (maze[i][size_tot.y - 2] == '*' && maze[i][size_tot.y - 3] == '*')
            maze[i][size_tot.y - 1] = '*';
    for (int j = 0; j < size_tot.y; ++j)
        if (maze[size_tot.x - 2][j] == '*' && maze[size_tot.x - 3][j] == '*')
            maze[size_tot.x - 1][j] = '*';
}

void generator(vector_t size_tot, bool perfect)
{
    char **maze = make_base_maze(size_tot);
    vector_t imperfect_cell = (size_tot.x >= 3 && size_tot.y >= 3) ?
    (vector_t){my_rand(1, size_tot.x - 2), my_rand(1, size_tot.y - 2)} :
    (vector_t){0, 0};

    if (size_tot.x == 0 || size_tot.y == 0)
        exit(84);
    simple_gen(size_tot, maze, perfect);
    remove_borders(maze, size_tot);
    maze[0][0] = '*';
    maze[size_tot.x - 1][size_tot.y - 1] = '*';
    print_word_array(maze, size_tot);
}
