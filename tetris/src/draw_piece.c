/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** draw_piece.c
*/

#include "../include/tetris.h"

void draw_one_piece_0(tetrimino_t tetrimino, int x, int y)
{
    for (int i = 0; i < tetrimino.size.y; ++i)
        for (int j = 0; j < my_strlen(tetrimino.piece[i]); ++j)
            tetrimino.piece[i][j] == '*' ? mvaddch(x + i, y + j, ' ') : 0;
}

void draw_one_piece_1(tetrimino_t tetrimino, int x, int y)
{
    for (int i = 0; i < tetrimino.size.y; ++i)
        for (int j = 0; j < my_strlen(tetrimino.piece[i]); ++j)
            tetrimino.piece[i][j] == '*' ? mvaddch(x + j, y + i, ' ') : 0;
}

void draw_one_piece_2(tetrimino_t tetrimino, int x, int y)
{
    for (int i = 0; i < tetrimino.size.y; ++i)
        for (int j = 0; j < my_strlen(tetrimino.piece[i]); ++j)
            tetrimino.piece[i][j] == '*' ? mvaddch((x + tetrimino.size.y - 1) - i, (y + tetrimino.size.x - 1) - j, ' ') : 0;
}

void draw_one_piece_3(tetrimino_t tetrimino, int x, int y)
{
    for (int i = 0; i < tetrimino.size.y; ++i)
        for (int j = 0; j < my_strlen(tetrimino.piece[i]); ++j)
            tetrimino.piece[i][j] == '*' ? mvaddch((x + tetrimino.size.y - 1) - j, (y + tetrimino.size.x - 1) - i, ' ') : 0;
}

void draw_one_piece(tetrimino_t tetrimino, int x, int y, int rotation)
{
    switch (rotation) {
        case 0:
            draw_one_piece_0(tetrimino, x, y);
            break;
        case 1:
            draw_one_piece_1(tetrimino, x, y);
            break;
        case 2:
            draw_one_piece_2(tetrimino, x, y);
            break;
        case 3:
            draw_one_piece_3(tetrimino, x, y);
            break;
        default:
            break;
    }
}
