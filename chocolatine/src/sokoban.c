/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** sokoban.c
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void my_exit(maps_t *info_maps, int ret) {
    endwin();
    my_freearray(info_maps->map);
    my_freearray(info_maps->save_map);
    exit(ret);
}

int sokoban(char **av) {
    int ch;
    maps_t info_maps;

    set_map(av[1], &info_maps);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    int row, col;
    getmaxyx(stdscr,row,col);
    while (check_storage(&info_maps)) {
        clear();
        print_map(info_maps.map);
        mvprintw(info_maps.pos.y, info_maps.pos.x, "P");
        ch = getch();
        if (ch == -1)
            my_exit(&info_maps, 84);
        move_item(ch, &info_maps);
        check_reset(ch, &info_maps);
        if (check_blocking_boxes(info_maps.map, info_maps.count_storage))
            my_exit(&info_maps, 1);
    }
    endwin();
}
