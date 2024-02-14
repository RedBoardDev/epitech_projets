/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_2.c
*/

#define NBR_PIECE 60

#include "include/screensaver.h"

void screensaver_2(init_sfml_t init_sfml)
{
    sfVector2i pts_a = {500, 100};
    sfVector2i pts_b = {WIDTH / 2, HEIGHT / 2};
    sfColor color = {255, 0, 0, 255};
    move_t move[NBR_PIECE];
    move_list(move, NBR_PIECE, 8, 1);

    while (sfRenderWindow_isOpen(init_sfml.window)) {
        clear_window(init_sfml.framebuffer, sfBlack);
        for (int m = 0; m < NBR_PIECE; ++m) {
            set_move(move, m, WIDTH, HEIGHT);
            set_points(&pts_a, &pts_b, move, m);
            draw_line(init_sfml.framebuffer, pts_a, pts_b, color);
        }
        color = my_rgb(color);
        events(init_sfml.window);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
