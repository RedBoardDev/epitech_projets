/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

int global_sig = 0;

int check_if_nbr(char *av)
{
    for (int i = 0; av[i] != '\0'; ++i)
        if (av[i] < '0' || av[i] > '9')
            return (0);
    return (1);
}

int get_map(char **av, players_t *my_map, players_t *enemy_map, game_t *infos)
{
    int return_val = 0;

    if (infos->player == 2)
        my_map->filepath = av[2];
    else
        my_map->filepath = av[1];
    init_map(my_map);
    return_val = set_file_map(my_map);
    init_map(enemy_map);
    return (return_val);
}

int check_arguments(int ac, game_t infos)
{
    int return_val = 0;

    if (infos.player == 2) {
        if (ac < 3 || ac > 3)
            return_val = 84;
    } else {
        if (ac > 2)
            return_val = 84;
    }
    return (return_val);
}

int navy(int ac, char **av)
{
    players_t my_map;
    players_t enemy_map;
    game_t infos;
    int win = 0;

    init_infos(&infos, av[1]);
    if (check_arguments(ac, infos) == 84)
        return (84);
    if (get_map(av, &my_map, &enemy_map, &infos) == 84 ||
    print_beginning(&my_map, &enemy_map, &infos) == 84)
        return (84);
    while (!infos.win) {
        infos.tour == infos.player ? play(&my_map, &enemy_map, &infos) :
        wait(&my_map, &enemy_map, &infos);
        if (infos.tour == 2) {
            my_putchar('\n');
            infos.win = print_map(&my_map);
            print_enemy_map(&enemy_map);
        }
        win = check_win2(&infos);
        infos.tour = (infos.tour == 1 ? 2 : 1);
    }
    return (win);
}
