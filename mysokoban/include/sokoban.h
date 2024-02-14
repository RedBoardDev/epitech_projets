/*
** EPITECH PROJECT, 2021
** PROJET-thomas.ott
** File description:
** projet.h
*/

#ifndef PROJET_H_
    #define PROJET_H_

    #include <ncurses.h>
    #include "structure.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int help_message(void);
int sokoban(char **av);
void print_map(char **map);
int get_size_file(char *path);
void reset_map(maps_t *info_maps);
void my_exit(maps_t *info_maps, int ret);
void move_item(int ch, maps_t *info_maps);
int check_size_terminal(maps_t info_maps);
int check_around(char **map, int y, int x);
int set_map(char *path, maps_t *info_maps);
void check_reset(int ch, maps_t *info_maps);
void send_boxes(maps_t *info_maps, int y, int x);
void my_exit_check_map(maps_t *info_maps, int ret);
void send_storage(maps_t *info_maps, int y, int x);
char **find_elements(char **map, maps_t *info_maps);
int check_blocking_boxes(char **map, int count_storage);
int push_boxing(int x, int y, int mouv, maps_t *info_maps);
int check_elements(char c, maps_t *info_maps, int y, int x);
int check_collisions(int x, int y, int mouv, maps_t *info_maps);
int check_storage(char **map, char **save_map, int count_storage);

#endif
