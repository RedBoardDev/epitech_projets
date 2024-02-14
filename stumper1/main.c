/*
** EPITECH PROJECT, 2022
** fractals
** File description:
** draw fractals
*/

#include "includes/my.h"
#include <unistd.h>

int isnumber(char *str)
{   
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' || str[i] <= '9')
            return (1);
    }
    return (0);
}

int space_len(char *str1)
{
    for (int i = 0; str1[i]; ++i) {
        if (str1[i] == '@')
            return (i);
    }
    return (0);
}

int check_str1(char *str1, int space_nbr, int str_i)
{
    int space = 0;

    for (int i = 0; str1[i] != '\0'; ++i) {
        if ((str_i == 1 && str1[i] != '#') && str1[i] != '.' && str1[i] != '@')
            return (84);
        str1[i] != '@' ? ++space : 0;
        if ((str1[i] == '@') && space != space_nbr)
            return (84);
        else if (str1[i] == '@')
            space = 0;
    }
    if (space != space_nbr)
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    int space_nbr = 0;

    if (argc != 4) {
        write(2, "Not enough arguments\n", 22);
        return (84);
    }
    if (!isnumber(argv[1])) {
        write(2, "Arguments 1 isnt number\n", 25);
        return (84);
    }
    if (my_strlen(argv[2]) == 0 || my_strlen(argv[3]) == 0)
        return (84);
    space_nbr = space_len(argv[2]);
    if (check_str1(argv[2], space_nbr, 1) || check_str1(argv[3], space_nbr, 0)) {
        write(2, "Wrong character. #, . and @ is good\n", 36);
        return (84);
    }
    create_patern(my_atoi(argv[1]) - 1, argv[2], argv[3], argv[2],0,0);
    return (0);
}
