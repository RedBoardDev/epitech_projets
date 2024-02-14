/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** error_handling3.c
*/

#include "include/bistromatic.h"
#include "include/error_handling.h"
#include "include/my.h"

int invalid_character_condition_av2(char c, char *av2, int i)
{
    int check_character2 = 1;

    for (int k = 0; av2[k] != 0;) {
        if (c == av2[k]) {
            check_character2 = 0;
            break;
        }
        if (av2[k] != 0)
            k++;
    }
    return check_character2;
}

int invalid_character(char *buff, char *av1, char *av2)
{
    char c;
    int check_av1 = 0;
    int check_av2 = 0;

    for (int i = 0; buff[i] != 0; ++i) {
        c = buff[i];
        check_av1 = invalid_character_condition_av1(c, av1, i);
        check_av2 = invalid_character_condition_av2(c, av2, i);
        if (check_av1 + check_av2 == 2) {
            my_putstr_error("syntax error");
            exit (EXIT_BASE);
        }
    }
    return 0;
}

int operator_in_base(char *av1)
{
    for (int i = 0; av1[i] != 0; i++) {
        if (is_default_op(av1[i]) == 1) {
            my_putstr_error("syntax error");
            exit (EXIT_BASE);
        }
    }
    return 0;
}

int two_identical_operators(char *av2)
{
    int occurence = 0;
    for (int k = 0; av2[k] != 0; k++) {
        occurence = 0;
        for (int i = 0; av2[i] != 0; i++) {
            if (av2[i] == av2[k]) {
                occurence++;
            }
        }
        if (occurence >= 2) {
            my_putstr_error("syntax error");
            exit (EXIT_BASE);
        }
    }
    return 0;
}