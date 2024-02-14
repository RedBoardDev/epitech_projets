/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** utils.c
*/

#include "../include/tetris.h"

void my_exit(int score, int return_value)
{
    put_backup(score);
    endwin();
    exit(return_value);
}

int my_rand(int min, int max)
{
    return (min + rand() % ((max + 1) - min));
}
