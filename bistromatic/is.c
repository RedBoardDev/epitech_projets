/*
** EPITECH PROJECT, 2021
** bistomatic
** File description:
** is.c
*/

#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int isparenthesis(char c, char const *arg2)
{
    if (c == arg2[0] || c == arg2[1])
        return (1);
    else
        return (0);
}

int is_default_op(char c)
{
    if (c == '-' || c == '+' || c == '/' || c == '%'
    || c == '*')
        return 1;
    return 0;
}

int isope(char c, char const *arg2)
{
    if (c == arg2[2] || c == arg2[3] || c == arg2[4] || c == arg2[5]
    || c == arg2[6])
        return (1);
    else
        return (0);
}

int prio(char str, linked_list_t *stack, char const *av2)
{
    if ((stack->data == '*' || stack->data == '/' || stack->data == '%') &&
    isope(str, av2))
        return (1);
    if ((stack->data == '-' || stack->data == '+') && (str == '+' ||
    str == '-'))
        return (1);
    return (0);
}
