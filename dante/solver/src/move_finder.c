/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** move_finder.c
*/

#include "../include/solver.h"
#include "../include/structure.h"

int init_finder(finder_t *finder)
{
    finder->direction = SOUTH;
    finder->pos_finder.x = 0;
    finder->pos_finder.y = 0;
}

int finder_south(solver_t *solver)
{
    if (solver->finder.pos_finder.y < solver->height && solver->map
    [solver->finder.pos_finder.y + 1][solver->finder.pos_finder.x] != 'X') {
        ++solver->finder.pos_finder.y;
        return (1);
    }
    return (0);
}

int finder_north(solver_t *solver)
{
    if (solver->finder.pos_finder.y > 0 && solver->map
    [solver->finder.pos_finder.y - 1]
    [solver->finder.pos_finder.x] != 'X') {
        --solver->finder.pos_finder.y;
        return (1);
    }
    return (0);
}

int finder_east(solver_t *solver)
{
    if (solver->finder.pos_finder.x < solver->widht && solver->map
    [solver->finder.pos_finder.y][solver->finder.pos_finder.x + 1] != 'X') {
        ++solver->finder.pos_finder.x;
        return (1);
    }
    return (0);
}

int finder_west(solver_t *solver)
{
    if (solver->finder.pos_finder.x > 0 && solver->map
    [solver->finder.pos_finder.y][solver->finder.pos_finder.x - 1] != 'X') {
        --solver->finder.pos_finder.x;
        return (1);
    }
    return (0);
}
