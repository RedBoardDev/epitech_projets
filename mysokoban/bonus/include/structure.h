/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** structure.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct maps_s {
    vector_t pos;
    vector_t player_start;
    char **map;
    char **save_map;
    int count_storage;
} maps_t;

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

typedef struct game_object_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
} game_object_t;

typedef struct play_data_s {
    int win;
    int start;
} play_data_t;

#endif
