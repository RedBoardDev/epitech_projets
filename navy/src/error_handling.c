/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** error_handling.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

int isletter_map(char c)
{
    if ((c >= 'A' && c <= 'H'))
        return (1);
    else
        return (0);
}

int isnum_map(char c)
{
    if (c >= '1' && c <= '8')
        return (1);
    else
        return (0);
}

int error_handling_map(char *buffer)
{
    int ret = 0;
    int j = 0;

    for (int i = 0; i < 4; ++i) {
        isnum(buffer[j++]) ? 0 : (ret = 84);
        for (int r = 0; r < 2; ++r) {
            buffer[j++] == ':' ? 0 : (ret = 84);
            isletter_map(buffer[j++]) ? 0 : (ret = 84);
            isnum_map(buffer[j++]) ? 0 : (ret = 84);
        }
        buffer[j++] == '\n' ? 0 : (ret = 84);
    }
    if (buffer[j] != '\0')
        ret = 84;
    ret == 0 ? ret = error_boats(buffer) : 0;
    return (ret);
}
