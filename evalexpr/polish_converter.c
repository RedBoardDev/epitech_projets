/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** polonais.c
*/

#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"

char *unstack(linked_list_t *stack, int var_y, char *y)
{
    while (stack) {
        if (stack && isope(stack->data)) {
            y[var_y] = stack->data;
            stack = pop(stack);
        } else
            stack = pop(stack);
        ++var_y;
    }
    return y;
}



char *polish(char *str)
{
    linked_list_t *stack = NULL;
    char *y = malloc(sizeof(char) * my_strlen(str) * 2);
    int var_y = 0;
    int bool = 0;

    for (int g = 0; g < my_strlen(str) * 2; ++g)
        y[g] = 0;
    for (int i = 0; i < my_strlen(str); ++i)
        y[i] = 0;
    stack = factory('(', stack);
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i - 1] == '(' && str[i] == '-') {
            bool = 1;
            ++i;
        }
        isnum(str[i]) ? y[var_y++] = str[i] : i;
        if (bool) {
            y[var_y] = str[i++];
            for (; isnum(str[i]); ++i)
                y[var_y++] = str[i];
            y[var_y++] = '_';
            bool = 0;
        }
        str[i] == '(' ? stack = factory(str[i], stack) : stack;
        if (isope(str[i]) && stack) {
            while (isope(stack->data) && prio(str[i], stack)) {
                y[var_y++] = stack->data;
                stack = pop(stack);
            }
            y[var_y++] = ' ';
            stack = factory(str[i], stack);
        }
        if (str[i] == ')') {
            for (; stack->data != '('; stack = pop(stack))
                y[var_y++] = stack->data;
            stack = pop(stack);
        }
    }
    return (unstack(stack, var_y, y));
}
