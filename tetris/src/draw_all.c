/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-tetris-martin.d-herouville
** File description:
** draw_all.c
*/

#include "../include/tetris.h"

void draw_timer(info_t info)
{
    int x = 19;
    int y = 9;
    int timer_m = 0;
    int timer_s = 0;
    double diff_s = difftime(time(NULL), info.t_begin);

    timer_m = (int)diff_s / 60;
    timer_s = (int)diff_s % 60;
    if (timer_m < 10) {
        mvprintw(9, x, "%d", 0);
        x++;
    }
    mvprintw(9, x, "%d", timer_m);
    x = 22;
    if (timer_s < 10) {
        mvprintw(9, x, "%d", 0);
        x++;
    }
    mvprintw(9, x, "%d", timer_s);
}

void draw_info_terminal(tetris_t *tetris)
{
    mvprintw(3, 20, "%d", tetris->info.high_score);
    mvprintw(4, 20, "%d", tetris->info.score);
    mvprintw(6, 20, "%d", tetris->info.lines);
    mvprintw(7, 20, "%d", tetris->info.level);
    draw_timer(tetris->info);
}

void draw_all(tetris_t *tetris)
{
    attron(COLOR_PAIR(FORE_WHITE));
    draw_interface(tetris);
    draw_info_terminal(tetris);
    attron(COLOR_PAIR(tetris->tetriminos[tetris->piece].color));
    draw_one_piece(tetris->tetriminos[tetris->piece], tetris->pos_piece.x,
    tetris->pos_piece.y, tetris->info.rotation);
    attron(COLOR_PAIR(tetris->tetriminos[tetris->next_piece].color));
    if (!tetris->args.without_next)
        draw_one_piece(tetris->tetriminos[tetris->next_piece],
        3, 42 + tetris->args.map_size.x, 0);
}
