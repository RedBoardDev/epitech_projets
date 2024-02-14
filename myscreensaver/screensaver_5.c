/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_4.c
*/

#include "include/screensaver.h"
#include "include/structur.h"
#include <math.h>
#define NBR_HORLOGE 8

int draw_horloge(sfUint8 *fm, int x, int y, char *buffer)
{
    for (int j = 0; j < 667; ++j) {
        for (int i = 0; i < 1000; ++i) {
            buffer[(i + (1000 + 1)  * j)] == '0' ?
            my_put_pixel(x + i, y + j, fm, sfWhite) : 0;
        }
    }
}

void turn_line(sfUint8 *fm, turn_vector_t line_vector, float i, sfColor color)
{
    sfVector2i pts_b = {0, 0};
    sfVector2i center = line_vector.pts_a;
    sfVector2i turn = line_vector.pts_b;

    pts_b.x = center.x + cos(i) * (turn.x - center.x) - sin(i) *
    (turn.y - center.y);
    pts_b.y = center.y + sin(i) * (turn.x - center.x) + cos(i) *
    (turn.y - center.y);
    draw_big_line(fm, center, pts_b, color, 5);
}

void screensaver_5(init_sfml_t init_sfml)
{
    sfVector2i center = {WIDTH / 2, HEIGHT / 2};
    sfClock *clock = sfClock_create();
    struct_img_t strct;
    turn_vector_t line_vector;
    line_vector.pts_a.x = HEIGHT / 2;
    line_vector.pts_a.y = WIDTH / 2;
    sfColor background_color = {115, 135, 152, 59.61};
    sfColor color_line = (sfColor){130, 39, 26, 255};
    int time = 0;
    float i_1 = 0;
    float i_2 = 0;
    float i_3 = 0;
    int speed = 3;
    move_t move[NBR_HORLOGE];

    move_list(move, NBR_HORLOGE, 4, 8);
    char *main_horloge = buffer_img_binary(667667, "bonus/horloge");
    strct.buffer = buffer_img_binary(22197, "bonus/horloge_2");
    strct.size_a = 147;
    strct.size_b = 150;
    while (sfRenderWindow_isOpen(init_sfml.window)) {
        sfRenderWindow_clear(init_sfml.window, background_color);
        time = sfClock_getElapsedTime(clock).microseconds/100000;
        clear_window(init_sfml.framebuffer, background_color);
        for (int m = 0; m < NBR_HORLOGE; ++m) {
            if (move[m].x <= 3 || move[m].x >= WIDTH - 150)
                move[m].incr_x *= (-1);
            if (move[m].y <= 0 || move[m].y >= HEIGHT - 147)
                move[m].incr_y *= (-1);
            move[m].x += move[m].incr_x * speed;
            move[m].y += move[m].incr_y * speed;
            draw_move_img(strct, init_sfml.framebuffer, &move[m], sfWhite);
        }
        if (time == 10) {
            sfClock_restart(clock);
            draw_horloge(init_sfml.framebuffer, 460, 210, main_horloge);
            line_vector.pts_b.x = 265;
            line_vector.pts_b.y = 970;
            turn_line(init_sfml.framebuffer, line_vector, i_1, color_line);
            line_vector.pts_b.x = 290;
            line_vector.pts_b.y = 970;
            turn_line(init_sfml.framebuffer, line_vector, i_2, color_line);
            line_vector.pts_b.x = 320;
            line_vector.pts_b.y = 970;
            turn_line(init_sfml.framebuffer, line_vector, i_3, color_line);
            i_1 -= 0.4;
            i_2 -= 0.1;
            i_3 -= 0.0108;
        }
        draw_horloge(init_sfml.framebuffer, 460, 210, main_horloge);
        line_vector.pts_b.x = 265;
        line_vector.pts_b.y = 970;
        turn_line(init_sfml.framebuffer, line_vector, i_1, color_line);
        line_vector.pts_b.x = 290;
        line_vector.pts_b.y = 970;
        turn_line(init_sfml.framebuffer, line_vector, i_2, color_line);
        line_vector.pts_b.x = 320;
        line_vector.pts_b.y = 970;
        turn_line(init_sfml.framebuffer, line_vector, i_3, color_line);
        events(init_sfml.window);
        function_sfml_whil(init_sfml, background_color);
    }
}
