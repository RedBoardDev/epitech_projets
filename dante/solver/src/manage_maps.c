/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** manage_file.c
*/

#include "../include/solver.h"
#include "../include/structure.h"

int get_size_file(char *filepath)
{
    struct stat stats;

    stat(filepath, &stats);
    return (stats.st_size);
}

void get_size_maze(solver_t *solver)
{
    int w = 0;
    int h = 0;

    while (solver->map[0][++w] != '\0');
    solver->widht = w - 1;
    while (solver->map[++h] != NULL);
    solver->height = h - 1;
}

int set_maps(char *filepath, solver_t *solver)
{
    int size = 0;
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    size = get_size_file(filepath);
    if (size < 4)
        exit(84);
    buffer = malloc(sizeof(char *) * size + 1);
    buffer[size] = '\0';
    rd = read(fd, buffer, size);
    if (rd == -1)
        return (84);
    close(fd);
    solver->map = my_str_to_word_array(buffer);
    get_size_maze(solver);
    free(buffer);
    return (0);
}
