/*
** EPITECH PROJECT, 2021
** navy
** File description:
** print.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

int print_map(players_t *player)
{
    int win = 1;

    my_putstr("my positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; ++i) {
        my_put_nbr(i + 1);
        my_putchar('|');
        for (int j = 0; j < 8; ++j) {
            isnum(player->map[i][j]) ? (win = 0) : 0;
            my_putchar(player->map[i][j]);
            j != 7 ? my_putchar(' ') : 0;
        }
        my_putchar('\n');
    }
    return (win);
}

void print_enemy_map(players_t *player)
{
    my_putchar('\n');
    my_putstr("enemy's positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; ++i) {
        my_put_nbr(i + 1);
        my_putchar('|');
        for (int j = 0; j < 8; ++j) {
            my_putchar(player->map[i][j]);
            j != 7 ? my_putchar(' ') : 0;
        }
        my_putchar('\n');
    }
}
