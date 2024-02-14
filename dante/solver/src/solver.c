/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** solver.c
*/

#include "../include/solver.h"
#include "../include/structure.h"

int check_start_and_end(solver_t *solver)
{
    return (solver->map[0][0] != '*'
    || solver->map[solver->height][solver->widht] != '*');
}

void search_solution(solver_t *solver)
{
    if (solver->finder.pos_finder.y == solver->height
    && solver->finder.pos_finder.x == solver->widht) {
        find_faster_path(solver);
        final_print(1, solver);
        exit(1);
    }
    set_number_case(solver);
    choose_case(solver);
}

int solver(char *filepath)
{
    solver_t solver;

    if (set_maps(filepath, &solver) == 84)
        return (44);
    solver.map_i = my_arraydup(solver.map, 24, 5);
    init_finder(&solver.finder);
    if (solver.height <= 1 || solver.widht <= 1)
        exit(84);
    if (check_start_and_end(&solver)) {
        printf("no solution found\n");
        exit(84);
    }
    search_solution(&solver);
    return (0);
}
