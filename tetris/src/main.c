/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/struct.h"
#include "../include/tetris.h"
#include <time.h>
#include <signal.h>

void sighandler_segv(int sig)
{
    exit(84);
}

tetris_t init_struct(int ac, char **av)
{
    tetris_t tet = {init_open_folder_maps(), get_args(ac, av),
    .piece = 0, .pos_piece = {4, my_rand(31, 31 + tet.args.map_size.x - 4)},
    .next_piece = 0, .info = {.high_score = 0, .level = 1, .lines = 0,
    .speed = 300000, .score = get_backup(), .t_begin = time(NULL),
    .rotation = 0}};
    return (tet);
}

int main(int ac, char **av)
{
    int ret = 0;
    tetris_t tetris;
    time_t time_buff;

    signal(SIGSEGV, sighandler_segv);
    tetris = init_struct(ac, av);
    srand((unsigned)time(&time_buff));
    tetris.piece = get_random_piece(&tetris);
    tetris.next_piece = get_random_piece(&tetris);
    if (tetris.args.debug)
        ret = debug(tetris);
    if (tetris.args.help)
        ret = print_help();
    if (!ret)
        tetris_fc(&tetris);
    return (0);
}
