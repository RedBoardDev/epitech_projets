/*
** EPITECH PROJECT, 2021
** evalexpr
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

int isparenthesis(char c)
{
    if (c == '(' || c == ')')
        return (1);
    else
        return (0);
}

int isope(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (1);
    else
        return (0);
}

int prio(char str, linked_list_t *stack)
{
    if ((stack->data == '*' || stack->data == '/' || stack->data == '%') &&
    isope(str))
        return (1);
    if ((stack->data == '-' || stack->data == '+') && (str == '+' ||
    str == '-'))
        return (1);
    return (0);
}
