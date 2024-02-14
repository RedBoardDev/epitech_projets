/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myscreensaver-thomas.ott
** File description:
** draw_utils.c
*/

#include "../include/screensaver.h"
#include "../include/structur.h"

void my_put_pixel(int w, int h, sfUint8 *framebuffer, sfColor color)
{
    OVERWIDTH(w);
    OVERHEIGHT(h);
    *(sfColor *)(4 * (h * WIDTH + w) + framebuffer) = color;
}

int draw_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b, sfColor color)
{
    int x = pts_a.x;
    int y = pts_b.y;

    for (float n = 0; n <= 1.0001; n += 0.0001) {
        my_put_pixel(x, y, fm, color);
        x = pts_a.x + (pts_b.x - pts_a.x) * n;
        y = pts_a.y + (pts_b.y - pts_a.y) * n;
    }
}

int draw_big_line(sfUint8 *fm, sfVector2i pts_a, sfVector2i pts_b, sfColor color, int radius)
{
    int x = pts_a.x;
    int y = pts_b.y;
    sfVector2i center;

    for (float n = 0; n <= 1.0001; n += 0.0001) {
        x = pts_a.x + (pts_b.x - pts_a.x) * n;
        y = pts_a.y + (pts_b.y - pts_a.y) * n;
        center.x = y;
        center.y = x;
        draw_circle(fm, center, radius, color);
    }
}

int draw_rectangle(sfVector2i pts_a, sfVector2i pts_b, sfUint8 *fm, sfColor c)
{
    for (int i = pts_a.x; i <= pts_b.x; ++i) {
        for (int y = pts_a.y; y <= pts_b.y; ++y) {
            my_put_pixel(i, y, fm, c);
        }
    }
}

int draw_circle(sfUint8 *fm, sfVector2i center, int radius, sfColor c)
{
    int xp = 0;
    int yp = 0;

    for (int x = center.x - radius; x <= center.x + radius * 2 ; x++) {
        for (int y = center.y - radius; y <= center.y + radius * 2; y++) {
            xp = (x - center.x) * (x - center.x);
            yp = (y - center.y) * (y - center.y);
            if (sqrt(xp + yp) < radius)
                my_put_pixel(x, y, fm, c);
        }
    }
}
