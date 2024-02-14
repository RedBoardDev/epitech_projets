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
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

#define WIDTH 1920
#define HEIGHT 1080
#define OBJ_NBR 9

int sokoban(init_sfml_t *init_sfml);
void print_map(char **map);
int check_storage(maps_t *info_maps);
void my_exit(maps_t *info_maps, int ret);
void move_item(int ch, maps_t *info_maps);
void check_reset(int ch, maps_t *info_maps);
void set_map(int maps, maps_t *info_maps);
int check_blocking_boxes(char **map, int count_storage);
int push_boxing(int x, int y, int mouv, maps_t *info_maps);
int check_collisions(int x, int y, int mouv, maps_t *info_maps);

int my_rand(int min, int max);
sfInt64 get_timeClock(sfClock *clock);
sfUint8 *framebuffer_create(int w, int h);
void function_sfml_whil(init_sfml_t *init_sfml, sfColor c);
void inits_obj(game_object_t *obj, init_sfml_t *init_sfml);
int analyse_events(init_sfml_t *init_sfml, game_object_t *obj, int mode);
void draw_sprite(init_sfml_t *init_sfml, game_object_t *obj);
void set_block_img(init_sfml_t *init_sfml, game_object_t *obj, sfVector2i pos_map, char c);
void menu(play_data_t *play_data, init_sfml_t *init_sfml, game_object_t *obj, maps_t *info_maps);
void game(play_data_t *play_data, init_sfml_t *init_sfml, game_object_t *obj, maps_t *info_maps);

#endif
