/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** print.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; --i)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; ++i)
        printf("%c", !(str[i] >= 97 && str[i] <= 122) ? str[i] : str[i] - 32);
    printf("\n");
}

void print_42(const char * str)
{
    str = str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    (action == PRINT_NORMAL ? print_normal(str) : (action == PRINT_REVERSE ?
    print_reverse(str) : (action == PRINT_UPPER ?
    print_upper(str) : (action == PRINT_42 ? print_42(str) : 0))));
}
