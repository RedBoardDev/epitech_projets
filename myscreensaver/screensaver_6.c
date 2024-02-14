/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myscreensaver-thomas.ott
** File description:
** screen_saver_6.c
*/

#include "include/screensaver.h"

void draw_rect_ctr(sfUint8 *fm, sfVector2i center, int radius, sfColor c)
{
    int xp = 0;
    int yp = 0;

    for (int x = center.x- radius; x <= center.x+ radius; x++) {
        for (int y = center.y- radius; y <= center.y + radius; y++) {
            xp = (x - center.x) * (x - center.x);
            yp = (y - center.y) * (y - center.y);
            my_put_pixel(x, y, fm, c);
        }
    }
}

void change_color(sfColor *color, int int_c)
{
    color->r = rand() % int_c;
    color->g = rand() % int_c;
    color->b = rand() % int_c;
}

void gestor_rect(init_sfml_t init_sfml)
{
    sfVector2i center;
    int radius = rand() % (150 + 1 - 40) + 40;
    sfColor color;
    int int_c = rand() % (255 + 1 - 100) + 100;

    color.a = rand() % (255 +1 - 200) + 200;
    change_color(&color, int_c);
    center.x = rand() % ((WIDTH - radius) + 1 - radius) + radius;
    center.y = rand() % ((HEIGHT - radius) + 1 - radius) + radius;
    draw_rect_ctr(init_sfml.framebuffer, center, radius, color);
    change_color(&color, int_c);
    draw_rect_ctr(init_sfml.framebuffer, center, radius / 1.3, color);
    change_color(&color, int_c);
    draw_rect_ctr(init_sfml.framebuffer, center, radius / 2, color);
    change_color(&color, int_c);
    draw_rect_ctr(init_sfml.framebuffer, center, radius / 3.4, color);
    change_color(&color, int_c);
    draw_rect_ctr(init_sfml.framebuffer, center, radius / 6.5, color);
}

void screensaver_6(init_sfml_t init_sfml)
{
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(init_sfml.window)) {
        if (sfClock_getElapsedTime(clock).microseconds/10000 == 8) {
            gestor_rect(init_sfml);
            sfClock_restart(clock);
        }
        events(init_sfml.window);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
