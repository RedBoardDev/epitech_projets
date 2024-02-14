/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-tetris-martin.d-herouville
** File description:
** debug.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/tetris.h"

void print_key(int key)
{
    if (key == KEY_RIGHT) {
        my_putstr("KEY_RIGHT (");
        return;
    }
    if (key == KEY_LEFT) {
        my_putstr("KEY_LEFT (");
        return;
    }
    if (key == KEY_DOWN) {
        my_putstr("KEY_DOWN (");
        return;
    }
    if (key == KEY_UP) {
        my_putstr("KEY_UP (");
        return;
    }
    my_putchar(key);
    my_putstr(" (");
}

void put_config_input(args_t args)
{
    my_putstr("Key left: ");
    print_key(args.key_left);
    my_put_nbr(args.key_left);
    my_putstr(")\nKey right: ");
    print_key(args.key_right);
    my_put_nbr(args.key_right);
    my_putstr(")\nKey turn: ");
    print_key(args.key_turn);
    my_put_nbr(args.key_turn);
    my_putstr(")\nKey drop: ");
    print_key(args.key_drop);
    my_put_nbr(args.key_drop);
    my_putstr(")\nKey quit: ");
    print_key(args.key_quit);
    my_put_nbr(args.key_quit);
    my_putstr(")\nKey pause: ");
    print_key(args.key_pause);
    my_put_nbr(args.key_pause);
    (args.without_next) ? my_putstr(")\nNext: No") : my_putstr(")\nNext: Yes");
}

void print_infos_one_tetrimino(tetrimino_t tet)
{
    my_putstr("Tetriminos '");
    my_putstr(tet.name);
    my_putstr("': ");
    if (!tet.active) {
        my_putstr("error\n");
        return;
    }
    my_putstr("size ");
    my_put_nbr(tet.size.x);
    my_putchar('*');
    my_put_nbr(tet.size.y);
    my_putstr(", color ");
    my_put_nbr(tet.color);
    my_putchar('\n');
    for (int j = 0; tet.piece[j]; ++j) {
        write(1, tet.piece[j], custom_strlen(tet.piece[j]));
        my_putchar('\n');
    }
}

void put_config_tetriminos(tetrimino_t *tetriminos)
{
    my_putstr("Number of tetriminos: ");
    my_put_nbr(tetriminos[0].size_struct);
    my_putchar('\n');
    for (int i = 0; i < tetriminos[0].size_struct; ++i)
        print_infos_one_tetrimino(tetriminos[i]);
}

int debug(tetris_t tetris)
{
    put_config_input(tetris.args);
    my_putstr("\nLevel: ");
    my_put_nbr(tetris.args.level);
    my_putstr("\nSize: ");
    my_put_nbr(tetris.args.map_size.x);
    my_putstr("*");
    my_put_nbr(tetris.args.map_size.y);
    my_putstr("\n\n");
    put_config_tetriminos(tetris.tetriminos);
    return (1);
}
