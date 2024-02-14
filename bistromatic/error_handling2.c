/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** error_handling2.c
*/

#include "include/bistromatic.h"
#include "include/error_handling.h"
#include "include/my.h"

int even_nbr(int var_test)
{
    if (var_test % 2 == 0)
        return 1;
    if (var_test % 2 == 1)
        return 0;
    return (84);
}

int error_parenthesis(char *buff, char *av2)
{
    unsigned int left_parenthesis = 0;
    unsigned int right_parenthesis = 0;
    unsigned int total_parenthesis = 0;

    for (int i = 0; buff[i] != 0; ++i) {
        if (buff[i] == av2[0])
            ++left_parenthesis;
        if (buff[i] == av2[1])
            ++right_parenthesis;
    }
    if (right_parenthesis >= 0 && left_parenthesis >= 0 && left_parenthesis
    != right_parenthesis) {
        my_putstr_error("syntax error");
        exit (EXIT_BASE);
    }
    return 0;
}

int my_two_arg_check(char *av1, char *av2)
{
    char c;

    for (int i = 0; av2[i] != 0; ++i) {
        c = av2[i];
        for (int j = 0; av1[j] != 0; ++j) {
            if (av1[j] == c) {
                my_putstr_error("syntax error");
                exit (EXIT_BASE);
            }
        }
    }
    return 0;
}

int invalid_character_condition_av1(char c, char *av1, int i)
{
    int check_character1 = 1;

    for (int j = 0; av1[j] != 0;) {
        if (c == av1[j]) {
            check_character1 = 0;
            break;
        }
        if (av1[j] != 0)
            j++;
    }
    return check_character1;
}
