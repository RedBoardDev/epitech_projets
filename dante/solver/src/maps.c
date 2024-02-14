/*
** EPITECH PROJECT, 2021
** B-CPE-200-MLH-2-1-dante-thomas.ott
** File description:
** maps.c
*/

#include "../include/solver.h"
#include "../include/structure.h"

void final_print(int found_path, solver_t *solver)
{
    printf("\n");
    if (found_path)
        for (int y = 0; y <= solver->height; ++y) {
            for (int x = 0; x <= solver->widht; ++x) {
                printf("%c", solver->map[y][x]);
            }
            printf("\n");
        }
    else
        printf("no solution found");
    my_freearray(solver->map);
}

void set_number_case(solver_t *solver)
{
    solver->map_i[solver->finder.pos_finder.y][solver->finder.pos_finder.x]
    += 1;
}

void set_casenumber_final(solver_t *solver, int *list, int x, int y)
{
    solver->map_i[y][x] = 99999;
    list[0] = y - 1 != -1 && solver->map_i[y - 1][x] > 0 ?
    solver->map_i[y - 1][x] : 99999;
    list[1] = x + 1 < solver->widht && solver->map_i[y][x + 1] > 0 ?
    solver->map_i[y][x + 1] : 99999;
    list[2] = y + 1 <= solver->height && solver->map_i[y + 1][x] > 0 ?
    solver->map_i[y + 1][x] : 99999;
    list[3] = x - 1 != -1 && solver->map_i[y][x - 1] > 0 ?
    solver->map_i[y][x - 1] : 99999;
}

void set_check_find_path(int *list, solver_t *solver)
{
    if (CHECK_FIND_PATH(0) && list[0] < list[1] &&
    list[0] < list[2] && list[0] < list[3]) {
        solver->finder.pos_finder.y -= 1;
        return;
    }
    if (CHECK_FIND_PATH(1) && list[1] < list[0] &&
    list[1] < list[2] && list[1] < list[3]) {
        solver->finder.pos_finder.x += 1;
        return;
    }
    else if (CHECK_FIND_PATH(2) && list[2] < list[0] &&
    list[2] < list[1] && list[2] < list[3]) {
        solver->finder.pos_finder.y += 1;
        return;
    }
    else if (CHECK_FIND_PATH(3) && list[3] < list[0] &&
    list[3] < list[1] && list[3] < list[2])
        solver->finder.pos_finder.x -= 1;
    return;
}

void find_faster_path(solver_t *solver)
{
    int list[4] = {0, 0, 0, 0};
    bool good = false;

    --solver->finder.pos_finder.x;
    solver->map[solver->finder.pos_finder.y][solver->finder.pos_finder.x] = 'O';
    while (!good) {
        set_casenumber_final(solver, list,
        solver->finder.pos_finder.x, solver->finder.pos_finder.y);
        set_check_find_path(list, solver);
        if (solver->finder.pos_finder.x == 0
        && solver->finder.pos_finder.y == 0)
            good = true;
        solver->map[solver->finder.pos_finder.y]
        [solver->finder.pos_finder.x] = 'O';
    }
    solver->map[solver->height][solver->widht] = 'O';
}
