/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_3.c
*/

#include "include/screensaver.h"
#include "include/structur.h"

int draw_circle_drugs_2(sfUint8 *framebuffer, sfVector2i center, int radius)
{
    int xp = 0;
    int yp = 0;
    sfColor color;

    color.a = 255;
    color.b = rand() % 100;
    color.g = 50;
    color.r = rand() % 10;
    for (int x = center.x - radius; x <= center.x + radius * 2 ; x++) {
        for (int y = center.y - radius; y <= center.y + radius * 2; y++) {
            xp = (x - center.x) * (x - center.x);
            yp = (y - center.y) * (y - center.y);
            if (sqrt(xp * yp) < radius)
                my_put_pixel(x, y, framebuffer, color);
        }
    }
}

int draw_plane(sfUint8 *fm, float x, float y, char *buffer, sfColor c,
int size_a, int size_b)
{
    for (int j = 0; j < size_a; ++j) {
        for (int i = 0; i < size_b; ++i) {
            buffer[(i + (size_b + 1)  * j)] == '0' ?
            my_put_pixel(x + i, y + j, fm, c) : 0;
        }
    }
}

void screensaver_3(init_sfml_t init_sfml)
{
    sfVector2i center = {500, 500};
    sfClock *clock = sfClock_create();
    int time = 0;
    float p = 0;
    float x_1 = 500;
    float y_1 = 900;
    float x_2 = 0;
    float y_2 = 800;
    float x_3 = 500;
    float y_3 = 0;
    float x_4 = WIDTH / 2;
    float y_4 = HEIGHT;
    char *p_2 = buffer_img_binary(21140, "bonus/plane_2");
    char *p_3 = buffer_img_binary(34136, "bonus/plane_3");
    char *p_4 = buffer_img_binary(12600, "bonus/plane_4");
    int speed = 1;
    float s = 0;

    while (sfRenderWindow_isOpen(init_sfml.window)) {
        time = sfClock_getElapsedTime(clock).microseconds/100000;
        if (time == 20) {
            if (s != 150)
                s += 50;
            else if (s >= 150)
                s = 0;
            sfClock_restart(clock);
            clear_window(init_sfml.framebuffer, sfBlack);
        }
        s < 50 ? (s += 0.08) : 0;
        draw_plane(init_sfml.framebuffer, x_2, y_2, p_2, sfBlack, 140, 150);
        draw_plane(init_sfml.framebuffer, (x_2 += 3.0 * speed), (y_2 -= (rand()
        % 4 / 2) * speed), p_2, sfWhite, 140, 150);

        draw_plane(init_sfml.framebuffer, x_3, y_3, p_3, sfBlack, 136, 250);
        draw_plane(init_sfml.framebuffer, (x_3 -= 3.0 * speed),
        (y_3 += 1 * speed), p_3, sfWhite, 136, 250);

        if (s < 50) {
            draw_plane(init_sfml.framebuffer, x_4, y_4, p_4, sfBlack, 150, 83);
            draw_plane(init_sfml.framebuffer, x_4, (y_4 -= 3 * s), p_4,
            sfWhite, 150, 83);
        }
        if (x_2 + 20 >= WIDTH) {
            draw_plane(init_sfml.framebuffer, x_2, y_2, p_2, sfBlack, 140, 150);
            x_2 = 0;
            y_2 = random() % 800 + 200;
        }
        if (x_3 + 100 <= 0) {
            draw_plane(init_sfml.framebuffer, x_3, y_3, p_3, sfBlack, 136, 250);
            x_3 = rand() % WIDTH - 100;
            y_3 = 0;
        }
        if (y_4 + 100 <= 0) {
            draw_plane(init_sfml.framebuffer, x_4, y_4, p_4, sfBlack, 150, 83);
            x_4 = rand() % WIDTH - 100;
            y_4 = HEIGHT;
            s = 50;
        }
        draw_circle_drugs_2(init_sfml.framebuffer, center, 20);
        center.x = rand() % WIDTH;
        center.y = rand() % HEIGHT;
        events(init_sfml.window);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
