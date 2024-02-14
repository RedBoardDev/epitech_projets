/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** inits_var.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

void init_map(players_t *player_struct)
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            player_struct->map[i][j] = '.';
}

void init_infos(game_t *infos, char *av)
{
    infos->enemy_pid = 0;
    infos->tour = 1;
    infos->win = false;
    infos->player = check_if_nbr(av) ? 2 : 1;
    infos->my_pid = getpid();
    infos->player == 2 ? infos->enemy_pid = my_atoi(av) : 0;
}
