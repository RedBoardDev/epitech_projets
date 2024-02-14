/*
** EPITECH PROJECT, 2021
** B-CPE-101-MLH-1-1-infinadd-thomas.ott
** File description:
** main.c
*/

#include "function.h"

int compare_len2(int av1, int av2)
{
    if (av1 < av2)
        return 1;
    else
        return 0;
}

void check_calcul(int bool, int bool_sub, char **av)
{
    if (bool == 1) {
        if (compare_len_sub(av[1], av[2]) == 0) {
            if (bool_sub == 1) {
                sub_calcul(av[2], av[1], 0);
            } else {
                my_putstr("-");
                sub_calcul(av[2], av[1], bool);
            }
        } else {
            if (bool_sub == 1) {
                my_putstr("-");
                sub_calcul(av[1], av[2], 0);
            } else
                sub_calcul(av[1], av[2], bool_sub);
        }
    } else
        add_calcul(av[1], av[2]);
}

int main (int ac, char **av)
{
    int bool = 0;
    int bool_sub = 0;

    if (av[1][0] == '-') {
        av[1][0] = '0';
        bool += 1;
        bool_sub = 1;
    }
    if (av[2][0] == '-') {
        av[2][0] = '0';
        bool += 1;
    }
    check_calcul(bool, bool_sub, av);
    return (0);
}
