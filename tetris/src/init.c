/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** init.c
*/

#include "../include/tetris.h"

void init_colors(void)
{
    for (int i = 0; i < 100; ++i)
        init_pair(i, COLOR_BLACK, i % 7 + 1);
    init_pair(FORE_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void inits_ncurses(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_colors();
}
