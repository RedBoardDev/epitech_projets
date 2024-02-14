/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** erro_handling.c
*/

#include "include/bistromatic.h"
#include "include/error_handling.h"
#include "include/my.h"

int two_identical_digits(char *av1)
{
    int occurence = 0;
    for (int k = 0; av1[k] != 0; k++) {
        occurence = 0;
        for (int i = 0; av1[i] != 0; i++) {
            if (av1[i] == av1[k])
                occurence++;
        }
        if (occurence >= 2) {
            my_putstr_error("syntax error");
            exit (EXIT_BASE);
        }
    }
    return 0;
}

void while_mathematic_error(int k, char *av2, char *buff, int i)
{
    if (k <= 6 && k >= 2) {
        if (buff[i] == av2[k] && buff[i + 1] == av2[4]) {
            my_putstr_error("syntax error");
            exit (EXIT_BASE);
        }
    }
}

int mathematic_error(char *buff, char *av2)
{
    int k = 0;
    char u;
    char b;

    for (int i = 0; buff[i] != 0; ++i) {
        for (int k = 0; av2[k] != 0; k++) {
            while_mathematic_error(k, av2, buff, i);
        }

    }
    return 0;
}

void all_error(char *buff, char *av1, char *av2, int size)
{
    mathematic_error(buff, av2);
    error_parenthesis(buff, av2);
    my_two_arg_check(av1, av2);
    operator_in_base(av1);
    invalid_character(buff, av1, av2);
    two_identical_operators(av2);
    two_identical_digits(av1);
}
