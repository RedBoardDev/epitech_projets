/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** utils.c
*/

#include "../include/teams.h"

bool isnumeric(const char *s)
{
    while (*s) {
        if (*s < '0' || *s > '9')
            return false;
        ++s;
    }
    return true;
}

void send_response(int socket, char *format, char *buffer)
{
    dprintf(socket, format, buffer);
}

char *replace_char(char *str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}

bool check_int_array_contain(int *array, int search_value)
{
    while (*array++ != -1)
        if (*array == search_value)
            return true;
    return false;
}
