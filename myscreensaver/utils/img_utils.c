/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myscreensaver-thomas.ott
** File description:
** img_utils.c
*/

#include "../include/screensaver.h"
#include "../include/structur.h"

char *buffer_img_binary(int size, char *name)
{
    char *buffer_1 = malloc(sizeof(char *) * size);

    read(open(name, O_RDONLY), buffer_1, size);
    return (buffer_1);
}

int draw_move_img(struct_img_t struct_img, sfUint8 *fm,
move_t *move, sfColor c)
{
    for (int j = 0; j < struct_img.size_a; ++j) {
        for (int i = 0; i < struct_img.size_b; ++i) {
            struct_img.buffer[(i + (struct_img.size_b + 1)  * j)] == '0' ?
            my_put_pixel(move->x + i, move->y + j, fm, c) : 0;
        }
    }
}

void set_move(move_t *move, int m, int w, int h)
{
    if (move[m].x <= 0 || move[m].x >= w)
        move[m].incr_x *= (-1);
    if (move[m].y <= 0 || move[m].y >= h)
        move[m].incr_y *= (-1);
    move[m].x += move[m].incr_x;
    move[m].y += move[m].incr_y;
}

void set_points(sfVector2i *pts_a, sfVector2i *pts_b, move_t *move, int m)
{
    pts_a->x = move[m].x;
    pts_a->y = move[m].y;
}

void move_list(move_t *move, int nb, int v_min, int v_max)
{
    for (int m = 0; m < nb; ++m) {
        move[m].incr_x = rand() % (v_max + 1 - v_min) + v_min;
        move[m].incr_y = rand() % (v_max + 1 - v_min) + v_min;
        move[m].x = rand() % (WIDTH - 200);
        move[m].y = rand() % (HEIGHT -200);
    }
}
