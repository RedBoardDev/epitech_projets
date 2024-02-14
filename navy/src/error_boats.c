/*
** EPITECH PROJECT, 2021
** navy
** File description:
** error_boats.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

int switch_sizes(int size, bool *size_boats)
{
    switch (size) {
        case 2:
            size_boats[0] = true;
            break;
        case 3:
            size_boats[1] = true;
            break;
        case 4:
            size_boats[2] = true;
            break;
        case 5:
            size_boats[3] = true;
            break;
        default:
            return (84);
    }
    return (0);
}

int check_all_bools(bool *size_boats)
{
    for (int i = 0; i < 4; ++i) {
        if (size_boats[i] == false)
            return (84);
    }
    return (0);
}

int check_size(char *buffer)
{
    if (buffer[0] != buffer[3]) {
        return (buffer[3] - buffer[0]);
    } else if (buffer[1] != buffer[4]) {
        return (buffer[4] - buffer[1]);
    } else
        return (0);
}

int error_boats(char *buffer)
{
    bool size_boats[4] = {false, false, false, false};
    int j = 0;
    int actual_size = 0;
    int ret = 0;

    for (int i = 0; i < 4; ++i) {
        actual_size = buffer[j] - 48;
        switch_sizes(actual_size, size_boats);
        j += 2;
        if (check_size(&buffer[j]) + 1 != actual_size)
            ret = 84;
        j += 6;
    }
    ret == 0 ? ret = check_all_bools(size_boats) : 0;
    return (ret);
}