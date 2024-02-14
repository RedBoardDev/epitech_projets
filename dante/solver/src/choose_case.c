/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** choose_case.c
*/

#include "../include/solver.h"
#include "../include/structure.h"

void direction_north(solver_t *solver)
{
    if (finder_west(solver)) {
        solver->finder.direction = WEST;
        search_solution(solver);
    }
    if (finder_north(solver)) {
        solver->finder.direction = NORTH;
        search_solution(solver);
    }
    if (finder_east(solver)) {
        solver->finder.direction = EAST;
        search_solution(solver);
    }
    set_number_case(solver);
    if (finder_south(solver)) {
        solver->finder.direction = SOUTH;
        search_solution(solver);
    }
}

void direction_south(solver_t *solver)
{
    if (finder_east(solver)) {
        solver->finder.direction = EAST;
        search_solution(solver);
    }
    if (finder_south(solver)) {
        solver->finder.direction = SOUTH;
        search_solution(solver);
    }
    if (finder_west(solver)) {
        solver->finder.direction = WEST;
        search_solution(solver);
    }
    set_number_case(solver);
    if (finder_north(solver)) {
        solver->finder.direction = NORTH;
        search_solution(solver);
    }
}

void direction_east(solver_t *solver)
{
    if (finder_north(solver)) {
        solver->finder.direction = NORTH;
        search_solution(solver);
    }
    if (finder_east(solver)) {
        solver->finder.direction = EAST;
        search_solution(solver);
    }
    if (finder_south(solver)) {
        solver->finder.direction = SOUTH;
        search_solution(solver);
    }
    set_number_case(solver);
    if (finder_west(solver)) {
        solver->finder.direction = WEST;
        search_solution(solver);
    }
}

void direction_west(solver_t *solver)
{
    if (finder_south(solver)) {
        solver->finder.direction = SOUTH;
        search_solution(solver);
    }
    if (finder_west(solver)) {
        solver->finder.direction = WEST;
        search_solution(solver);
    }
    if (finder_north(solver)) {
        solver->finder.direction = NORTH;
        search_solution(solver);
    }
    set_number_case(solver);
    if (finder_east(solver)) {
        solver->finder.direction = EAST;
        search_solution(solver);
    }
}

int choose_case(solver_t *solver)
{
    if (solver->finder.direction == NORTH)
        direction_north(solver);
    if (solver->finder.direction == SOUTH)
        direction_south(solver);
    if (solver->finder.direction == EAST)
        direction_east(solver);
    if (solver->finder.direction == WEST)
        direction_west(solver);
}
