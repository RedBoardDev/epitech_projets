/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

typedef struct screen_s {
    bool main_menu;
    bool create_menu;
    bool load_menu;
    bool world;
    int soundbox;
} screen_t;

typedef struct gui_world_s {
    bool painter;
    bool toggle_move;
    bool toggle_rotate;
    bool rotate_360;
} gui_world_t;

typedef struct sound_s {
    sfSound *click;
    sfSound *launch_maps;
    sfSound *gngngn;
    float volume;
    float volume_backup;
} sound_t;

typedef struct text_runtime_s {
    char *hauteur;
    char *largeur;
    char *filename_save;
    bool hauteur_b;
    bool largeur_b;
    bool filename_save_b;
} text_runtime_t;

typedef struct fps_s {
    sfClock *clock;
    float timer;
} fps_t;

typedef struct beginning_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    screen_t screen;
    gui_world_t guiworld;
    bool init_map;
    bool load_map;
    bool get_file;
    bool save_file;
    sound_t sound;
    text_runtime_t text;
    fps_t fps;
} beginning_t;

typedef struct mouse_s {
    bool left;
    bool left_released;
    bool right;
    int move_x;
    int move_y;
    sfVector2i pos;
} mouse_t;

typedef struct mouse_wheel_s {
    bool up;
    bool down;
    bool click;
} mouse_wheel_t;

typedef struct events_s {
    bool left;
    bool right;
    bool up;
    bool down;
    bool page_up;
    bool page_down;
    bool z;
    bool s;
    bool q;
    bool d;
    bool p;
    bool m;
    bool escape;
    bool space;
    bool ctrl;
    bool tab;
    bool enter;
    mouse_t mouse;
    mouse_wheel_t mouse_wheel;
} events_t;

typedef struct vector_3i_s {
    int x;
    int y;
    int z;
} vector_3i_t;

typedef struct point_s {
    sfVector2f iso;
    vector_3i_t coords;
} point_t;

typedef struct map_s {
    point_t **map_2d;
    point_t **backup_2d;
    int **map_3d;
    int **backup_3d;
    sfVector2i size;
    sfVector2i angle;
    sfVector2i pos;
    int zoom;
    int radius;
    bool painter;
} map_t;

typedef struct my_quad_s {
    point_t a;
    point_t b;
    point_t c;
    point_t d;
} my_quad_t;

typedef struct spritesheet_s {
    bool active;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} spritesheet_t;

typedef struct text_s {
    char *str;
    int size;
    sfVector2f pos;
    sfColor color;
} text_t;

typedef struct load_button_s {
    int count;
    char *name_file;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    bool mouse_on;
} load_button_t;

typedef struct init_sprite_s {
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
} init_sprite_t;

typedef struct world_s {
    map_t maps;
    beginning_t begin;
    events_t all_events;
    spritesheet_t *spritesheet;
    load_button_t *load_button;
} world_t;

#endif
