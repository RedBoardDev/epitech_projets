/*
** EPITECH PROJECT, 2021
** dante
** File description:
** make_cell.c
*/

#include "../include/generator.h"
#include "../include/struct.h"
#include <unistd.h>

vector_t get_delta_with_random(int random)
{
    vector_t delta = {0, 0};

    if (random == 0)
        delta.x = 1;
    if (random == 1)
        delta.y = 1;
    if (random == 2)
        delta.x = -1;
    if (random == 3)
        delta.y = -1;
    return (delta);
}

vector_t add_two_vectors(vector_t a, vector_t b)
{
    return ((vector_t){a.x + b.x, a.y + b.y});
}

bool check_cell(char **maze, vector_t first, vector_t second, vector_t size_tot)
{
    return ((second.x >= 0 && second.x < size_tot.x && second.y >= 0 &&
    second.y < size_tot.y && maze[first.x][first.y] == 'X' &&
    maze[second.x][second.y] == 'X' && (second.x != 0 || second.y != 0)));
}

void make_cell(char **maze, vector_t size_tot, int i, int j)
{
    vector_t first;
    vector_t second;
    vector_t delta;
    for (int count = 0, random = my_rand(0, 3); count < 4;) {
        delta = get_delta_with_random(random);
        first = add_two_vectors((vector_t){i, j}, delta);
        second = add_two_vectors(first, delta);
        if (check_cell(maze, first, second, size_tot)) {
            maze[first.x][first.y] = '*';
            maze[second.x][second.y] = '*';
            i = second.x;
            j = second.y;
            random = my_rand(0, 3);
            count = 0;
        } else {
            random = (random + 1) % 4;
            ++count;
        }
    }
}
