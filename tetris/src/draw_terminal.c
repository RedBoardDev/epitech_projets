/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-tetris-martin.d-herouville
** File description:
** draw_terminal.c
*/

#include "../include/tetris.h"

void draw_stats_box(int x, int y)
{
    mvprintw(y++, x, "/-------STATS-------\\");
    mvprintw(y++, x, "| High Score:       |");
    mvprintw(y++, x, "| Score:            |");
    mvprintw(y++, x, "|                   |");
    mvprintw(y++, x, "| Lines:            |");
    mvprintw(y++, x, "| Level:            |");
    mvprintw(y++, x, "|                   |");
    mvprintw(y++, x, "| Timer:        :   |");
    mvprintw(y++, x, "\\-------------------/");
}

void draw_title_game(int x, int y)
{
    mvprintw(y++, x, "/---------------\\");
    mvprintw(y++, x, "|               |");
    mvprintw(y++, x, "|  Play TETRIS  |");
    mvprintw(y++, x, "|  Project PSU  |");
    mvprintw(y++, x, "|               |");
    mvprintw(y++, x, "\\---------------/");
}

void draw_map_box(int x, int y, vector_t map_size)
{
    int x2 = x;

    mvprintw(y, x2++, "+");
    for (int g = 0; g < map_size.x; ++g, x2++)
        mvprintw(y, x2, "-");
    mvprintw(y++, x2++, "+");
    for (int i = 0, x2 = x; i < map_size.y; ++i, y++, x2 = x) {
        mvprintw(y, x2, "|");
        for (int g = 0; g <= map_size.x; ++g, x2++);
        mvprintw(y, x2, "|");
    }
    x2 = x;
    mvprintw(y, x2++, "+");
    for (int g = 0; g < map_size.x; ++g, x2++)
        mvprintw(y, x2, "-");
    mvprintw(y, x2++, "+");
}

int draw_next_box(int x, int y)
{
    mvprintw(y++, x, "/-------NEXT-------\\");
    mvprintw(y++, x, "|                  |");
    mvprintw(y++, x, "|                  |");
    mvprintw(y++, x, "|                  |");
    mvprintw(y++, x, "|                  |");
    mvprintw(y++, x, "\\------------------/");
}

void draw_interface(tetris_t *tet)
{
    draw_stats_box(5, 2);
    draw_title_game(7, 14);
    draw_map_box(30, 3, tet->args.map_size);
    if (!tet->args.without_next)
        draw_next_box(35 + tet->args.map_size.x, 2);
}
