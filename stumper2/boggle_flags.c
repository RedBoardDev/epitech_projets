/*
** EPITECH PROJECT, 2022
** Boggle
** File description:
** stumper
*/

#include "my.h"
#include "structure.h"
#include <unistd.h>

int check_size(int size, char *str)
{
    int len = my_strlen(str);

    if ((size * size) == len)
        return (0);
    write(2, "the size is not good\n", 21);
    return (84);
}

int check_arg_word(char **argv, int arg_i, int argc, boggle_t *boggle)
{
    if (argc != arg_i && my_strcmp(argv[arg_i], "-w") == 0) {
        if (!my_str_isstr(argv[arg_i + 1])) {
            write(2, "You must use numbers\n", 21);
            return (84);
        }
        boggle->word = argv[arg_i + 1];
    } else
        boggle->word = "\0";
    return (0);
}

int check_args_size(char **argv, int arg_i, int argc, boggle_t *boggle)
{
    if (argc < 3 && argc > 7 || argc % 2 == 0)
        return (84);
    if (argc > 4 && my_strcmp(argv[3], "-s") == 0) {
        if (!my_str_isnum(argv[4])) {
            write(2, "You must use letters\n", 21);
            return (84);
        }
        boggle->size = my_atoi(argv[4]);
        return (5);
    } else
        boggle->size = 4;
    return (0);
}

int check_args_grid(char **argv, int argc)
{
    if (argc < 3 || argc == 4 || argc == 6 ||
        argc > 7 || my_strcmp(argv[1], "-g")) {
        write(2, "You must use letters\n", 21);
        return (84);
    }
    if (!my_str_isstr(argv[2])) {
        write(2, "You muste use -g GRID\n", 21);
        return (84);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int ret = 84;
    int arg_i = 3;
    boggle_t boggle;

    if (check_args_grid(argv, argc) == 84)
        return (84);
    boggle.grid = argv[2];
    ret = check_args_size(argv, arg_i, argc, &boggle);
    if (ret == 84)
        return (84);
    else if (ret == 5)
        arg_i = 5;
    if (check_arg_word(argv, arg_i, argc, &boggle) == 84)
        return (84);
    if (check_size(boggle.size, boggle.grid) == 84)
        return (84);
    boggle.grid[boggle.size * boggle.size] = '\0';
    main_clock(boggle);
    return 0;
}
