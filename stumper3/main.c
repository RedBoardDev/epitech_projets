/*
** EPITECH PROJECT, 2021
** test
** File description:
** main.c
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_number(char *str)
{
    int nbr = 0;

    nbr = atoi(str);
    return (nbr);
}

void error_handle_good(char *str, int nbr, char **argv)
{
    if (strcmp(argv[1], "-f") == 0) {
        str = get_file(argv[2]);
        start_decypher(str, nbr);
        free(str);
        exit(0);
    }
    if (strcmp(argv[1], "-s") == 0) {
        start_decypher(argv[2], nbr);
        exit(0);
    }
}

int main(int argc, char **argv)
{
    char *str;
    int nbr = 0;

    if (argc != 4) {
        write(2, "You must have 3 arguments\n", 26);
        return (84);
    }
    if (!my_str_isnum(argv[3]))
        return (84);
    nbr = get_number(argv[3]);
    nbr %= 26;
    error_handle_good(str, nbr, argv);
    return (84);
}
