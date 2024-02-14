/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_1.c
*/

#include "include/screensaver.h"

int draw_circle_drugs(sfUint8 *framebuffer, sfVector2i center, int radius)
{
    int xp = 0;
    int yp = 0;
    sfColor color;

    for (int x = center.x - radius; x <= center.x + radius * 2 ; x++) {
        for (int y = center.y - radius; y <= center.y + radius * 2; y++) {
            xp = (x - center.x) * (x - center.x);
            yp = (y - center.y) * (y - center.y);
            if (sqrt(xp + yp) < radius)
                my_put_pixel(x, y, framebuffer, color);
        }
        color.a = rand() % 255;
        color.b = rand() % 210;
        color.g = rand() % 230;
        color.r = rand() % 1;
    }
}

void screensaver_1(init_sfml_t init_sfml)
{
    sfVector2i center = {500, 500};
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(init_sfml.window)) {
        if (sfClock_getElapsedTime(clock).microseconds/100000 == 30) {
            sfClock_restart(clock);
            clear_window(init_sfml.framebuffer, sfBlack);
        }
        draw_circle_drugs(init_sfml.framebuffer, center, 50);
        center.x = rand() % WIDTH;
        center.y = rand() % HEIGHT;
        events(init_sfml.window);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
