/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver.h
*/

#ifndef SCREENSAVER_H_
    #define SCREENSAVER_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "structur.h"

#define WIDTH 1920
#define HEIGHT 1080
#define OBJ_NBR 10


sfColor my_rgb(sfColor color);
int clear_window(sfUint8 *fm, sfColor c);
sfUint8 *framebuffer_create(int w, int h);
int draw_big_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b,
sfColor color, int radius);
int draw_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b, sfColor color);
void my_put_pixel(int w, int h, sfUint8 *framebuffer, sfColor color);
sfUint8 *framebuffer_create(int w, int h);
void function_sfml_whil(init_sfml_t *init_sfml, sfColor c);
int draw_rectangle(sfVector2i pts_a, sfVector2i pts_b, sfUint8 *fm, sfColor c);
int draw_circle(sfUint8 *fm, sfVector2i center, int radius, sfColor c);
int analyse_events(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data);
int main(int avc, char **avg);
void my_runner(init_sfml_t *init_sfml, sfClock *clock);
void inits_obj(game_object_t *obj, init_sfml_t *init_sfml);
void draw_lazer(init_sfml_t *init_sfml, game_object_t *obj);
int my_rand(int min, int max);
void put_score(int nbr, init_sfml_t *init_sfml);
int is_collided_sprite(game_object_t *obj);
play_data_t init_play_data();

// inits_obj
void inits_paralax(game_object_t *obj, init_sfml_t *init_sfml);
void inits_lazer(game_object_t *obj, init_sfml_t *init_sfml);
void inits_scientifists(game_object_t *obj, init_sfml_t *init_sfml);
void inits_player(game_object_t *obj, init_sfml_t *init_sfml);

//missile
void sprite_missile(game_object_t *obj);
void manage_missile(init_sfml_t *init_sfml, game_object_t *obj);

//menu
void put_main_menu(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant);

//put_sprite
void manage_draw_sprite(init_sfml_t *init_sfml, game_object_t *obj);
int draw_sprite_walk(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant);

//move
void move_scientifist(init_sfml_t *init_sfml, game_object_t *obj, float speed);
int move_parallax(init_sfml_t *init_sfml, game_object_t *obj);

//utilscsfml
sfInt64 get_timeClock(sfClock *clock);
void set_sprite_pos_texture(init_sfml_t *init_sfml, game_object_t *obj);

//inits
void inits_sounds(sound_ambiant_t *sound_ambiant);

//dead
void is_dead(play_data_t *play_data, sound_ambiant_t *sound_ambiant,
game_object_t *obj, init_sfml_t *init_sfml);
void set_pos_object(game_object_t *obj, int top, int left, int width);

//events
int events_close_window(init_sfml_t *init_sfml);

#endif
