/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** structur.h
*/

#include "screensaver.h"

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct init_sfml_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} init_sfml_t;

typedef struct vector_s {
    sfVector2i center;
    sfVector2i body_a;
    sfVector2i body_b;
} vector_t;

typedef struct move_s {
    int x;
    int y;
    int incr_x;
    int incr_y;
} move_t;

typedef struct turn_vector_s {
    sfVector2i pts_a;
    sfVector2i pts_b;
} turn_vector_t;

typedef struct struct_img_s {
    sfUint8 *fm;
    float x;
    float y;
    int size_a;
    int size_b;
    char *buffer;
} struct_img_t;

#endif
