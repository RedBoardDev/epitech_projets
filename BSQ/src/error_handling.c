/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-BSQ-thomas.ott
** File description:
** error_handling.c
*/

#include "../include/bsq.h"
#include "../include/my.h"

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int error_same_line_size(char *data, int size, unsigned int len_nb)
{
    int count = 0;
    int first_line = len_ligne(data);
    int nb_line = 0;
    int y = 0;

    for (int y = 0; data[y] != '\0'; ++y) {
        if (data[y] != '.' && data[y] != 'o' && data[y] != '\n'
        && data[y] != ' ')
            exit(84);
        if (data[y] == '\n') {
            ++nb_line;
            if (first_line != count)
                exit(84);
            count = 0;
        } else
            ++count;
    }
    return (nb_line);
}

void error_number_column(char *buffer)
{
    for (int i = 0; buffer[i] != '\n'; ++i)
        !isnum(buffer[i]) ? exit(84) : 0;
}

