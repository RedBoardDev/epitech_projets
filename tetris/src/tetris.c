/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-tetris-martin.d-herouville
** File description:
** tetris.c
*/

#include "../include/tetris.h"

int get_random_piece(tetris_t *tetris)
{
    bool check = true;
    int random;

    while (check) {
        random = my_rand(0, tetris->tetriminos[0].size_struct - 1);
        if (tetris->tetriminos[random].active)
            check = false;
    }
    return (random);
}

void check_input(tetris_t *tetris)
{
    int ch = getch();

    if (ch != ERR) {
        if (ch == tetris->args.key_quit)
            my_exit(tetris->info.score, 0);
        if (ch == 'c') {
            tetris->piece = tetris->next_piece;
            tetris->next_piece = get_random_piece(tetris);
            tetris->pos_piece.y =
            my_rand(31, 31 + tetris->args.map_size.x - 4);
        }
        if (ch == tetris->args.key_right)
            tetris->pos_piece.y =
            (tetris->pos_piece.y < 31 + tetris->args.map_size.x - tetris->tetriminos[tetris->piece].size.x ?
            tetris->pos_piece.y + 1 : tetris->pos_piece.y);
        if (ch == tetris->args.key_left)
            tetris->pos_piece.y = (tetris->pos_piece.y > 31 ?
            tetris->pos_piece.y - 1 : tetris->pos_piece.y);
        if (ch == tetris->args.key_turn) {
            tetris->info.rotation = (tetris->info.rotation < 3) ?
            tetris->info.rotation + 1 : 0;
        }
        if (ch == tetris->args.key_drop)
            tetris->pos_piece.x += 1;
    }
}

int tetris_fc(tetris_t *tetris)
{
    clock_t my_clock = clock() + 1 * tetris->info.speed;

    inits_ncurses();
    while (true) {
        erase();
        draw_all(tetris);
        if (clock() > my_clock) {
            my_clock += 1 * tetris->info.speed;
            tetris->pos_piece.x += 1;
        }
        if (tetris->pos_piece.x - 5 >= tetris->args.map_size.y - tetris->tetriminos[tetris->piece].size.y) {
            tetris->pos_piece.x = 4;
            tetris->piece = tetris->next_piece;
            tetris->next_piece =
            tetris->next_piece = get_random_piece(tetris);
        }
        check_input(tetris);
        refresh();
    }
    endwin();
    return (0);
}
