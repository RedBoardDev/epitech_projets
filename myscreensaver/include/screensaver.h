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
    #include "structur.h"

#define WIDTH 1920
#define HEIGHT 1080

#define OVERWIDTH(w)    w <= 0 ? w = 1: w; \
                        w >= WIDTH ? w = WIDTH - 1 : w;
#define OVERHEIGHT(h)   h <= 0 ? h = 1: h; \
                        h >= HEIGHT ? h = HEIGHT - 1 : h;

void screensaver_1(init_sfml_t init_sfml);
void screensaver_2(init_sfml_t init_sfml);
void screensaver_3(init_sfml_t init_sfml);
void screensaver_4(init_sfml_t init_sfml);
void screensaver_5(init_sfml_t init_sfml);
void screensaver_6(init_sfml_t init_sfml);
sfColor my_rgb(sfColor color);
void move_list(move_t *move, int nb, int v_min, int v_max);
int clear_window(sfUint8 *fm, sfColor c);
sfUint8 *framebuffer_create(int w, int h);
char *buffer_img_binary(int size, char *name);
int draw_big_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b,
sfColor color, int radius);
int draw_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b, sfColor color);
void events(sfRenderWindow *window);
void my_put_pixel(int w, int h, sfUint8 *framebuffer, sfColor color);
sfUint8 *framebuffer_create(int w, int h);
void function_sfml_whil(init_sfml_t init_sfml, sfColor c);
int draw_move_img(struct_img_t struct_img, sfUint8 *framebuffer,
move_t *move, sfColor c);
int draw_rectangle(sfVector2i pts_a, sfVector2i pts_b, sfUint8 *fm, sfColor c);
int draw_circle(sfUint8 *fm, sfVector2i center, int radius, sfColor c);
void set_move(move_t *move, int m, int w, int h);
void set_points(sfVector2i *pts_a, sfVector2i *pts_b, move_t *move, int m);

#endif