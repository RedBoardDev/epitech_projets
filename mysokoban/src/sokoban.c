/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** sokoban.c
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void check_win_or_lose(maps_t *info_maps)
{
    if (!check_storage(info_maps->map, info_maps->save_map,
    info_maps->count_storage))
        my_exit(info_maps, 0);
    else if (check_blocking_boxes(info_maps->map, info_maps->count_storage))
        my_exit(info_maps, 1);
}

int get_getch(maps_t *info_maps)
{
    int ch = getch();

    if (ch == -1)
        my_exit(info_maps, 84);
    return (ch);
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL ; ++i)
        printw(map[i]);
}

int sokoban(char **av)
{
    int ch;
    maps_t info_maps;

    if (set_map(av[1], &info_maps) == 84)
        return (84);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    while (true) {
        clear();
        print_map(info_maps.map);
        mvprintw(info_maps.pos.y, info_maps.pos.x, "P");
        refresh();
        check_win_or_lose(&info_maps);
        ch = get_getch(&info_maps);
        move_item(ch, &info_maps);
        check_reset(ch, &info_maps);
    }
    endwin();
    return (0);
}
