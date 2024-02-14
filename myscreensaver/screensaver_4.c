/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_5.c
*/

#include "include/screensaver.h"
#include "include/structur.h"
#include <math.h>
#define NBR_BITCON 5

void screensaver_4(init_sfml_t init_sfml)
{
    struct_img_t strct;
    sfVector2i center = {WIDTH / 2, HEIGHT / 2};
    sfClock *clock = sfClock_create();
    sfVector2i pts_a = {HEIGHT / 2, WIDTH / 2};
    sfVector2i pts_b = {500, 700};
    sfColor background_color = sfBlack;
    int time = 0;
    move_t move[NBR_BITCON];
    move_list(move, NBR_BITCON, 4, 10);
    strct.buffer = buffer_img_binary(90300, "bonus/bitcoin");
    strct.size_a = 300;
    strct.size_b = 300;
    while (sfRenderWindow_isOpen(init_sfml.window)) {
        sfRenderWindow_clear(init_sfml.window, background_color);
        time = sfClock_getElapsedTime(clock).microseconds/100000;
        clear_window(init_sfml.framebuffer, background_color);
        for (int m = 0; m < NBR_BITCON; ++m) {
            set_move(move, m, WIDTH - 300, HEIGHT - 300);
            draw_move_img(strct, init_sfml.framebuffer, &move[m], sfYellow);
        }
        events(init_sfml.window);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
