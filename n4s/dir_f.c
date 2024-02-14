/*
** EPITECH PROJECT, 2022
** B-AIA-200-MLH-2-1-bsn4s-luca.haumesser
** File description:
** dir_f
*/

#include "struct.h"

void right_move(struct_t *data)
{
    data->dir = -0.1;
    if (data->cur_pos_16 <= 1400 && data->cur_pos_3 <= 550)
        data->dir = -0.15;
    if (data->cur_pos_16 <= 1200 && data->cur_pos_3 <= 600)
        data->dir = -0.18;
    if (data->cur_pos_16 <= 1100 && data->cur_pos_3 <= 550)
        data->dir = -0.2;
}

void left_move(struct_t *data)
{
    data->dir = 0.1;
    if (data->cur_pos_16 <= 1400 && data->cur_pos_28 <= 550)
        data->dir = 0.15;
    if (data->cur_pos_16 <= 1200 && data->cur_pos_28 <= 600)
        data->dir = 0.18;
    if (data->cur_pos_16 <= 1100 && data->cur_pos_28 <= 550)
        data->dir = 0.2;
}

void other_move(struct_t *data)
{
    if (data->cur_pos_3 <= 500 && data->cur_pos_28 <= 500 &&
    data->cur_pos_3 < data->cur_pos_28) {
        data->dir = 0.15;
        return;
    }
    if (data->cur_pos_3 <= 500 && data->cur_pos_28 <= 500 &&
    data->cur_pos_3 > data->cur_pos_28) {
        data->dir = -0.15;
        return;
    }
    if (data->cur_pos_3 >= 1300 && data->cur_pos_28 >= 1300 &&
    data->dir <= 0.1) {
        data->dir = -0.05;
        return;
    }
    if (data->cur_pos_3 >= 1300 && data->cur_pos_28 >= 1300 &&
    data->dir >= -0.1) {
        data->dir = 0.05;
        return;
    }
    data->dir = 0;
}

void change_dir(struct_t *data)
{
    if (data->cur_pos_16 <= 400) {
        data->speed = 0.05;
        if (data->cur_pos_3 > data->cur_pos_28)
            data->dir = 0.8;
        if (data->cur_pos_3 < data->cur_pos_28)
            data->dir = -0.8;
        return;
    }
    if (data->cur_pos_16 <= 1400 && data->cur_pos_3 <= 600) {
        right_move(data);
        return;
    }
    if (data->cur_pos_16 <= 1400 && data->cur_pos_28 <= 600) {
        left_move(data);
        return;
    }
    other_move(data);
}
