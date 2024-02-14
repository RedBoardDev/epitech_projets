/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** structur.h
*/

#include "my_runner.h"
#include <stdbool.h>

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct init_sfml_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    bool infini;
    char **map;
    float speed_coef;
    sfClock *clock;
} init_sfml_t;

typedef struct game_clock_s {
    sfClock *lazer_sprite;
    sfClock *missile_sprite;
    sfClock *fly_sprite;
} game_clock_t;

typedef struct game_object_s {
    int jump;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
    int pos_incr;
    sfClock *clock;
    game_clock_t game_clock;
} game_object_t;

typedef struct play_data_s {
    int sprite;
    float score;
    int start;
    int speed;
} play_data_t;

typedef struct sound_ambiant_s {
    sfMusic *walk;
    sfMusic *rocket;
    sfMusic *main;
} sound_ambiant_t;

#endif
