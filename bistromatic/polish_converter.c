/*
** EPITECH PROJECT, 2021
** bistomatic
** File description:
** polonais.c
*/

#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/bistromatic.h"

char *unstack(linked_list_t *stack, int var_y, char *y, char const *arg2)
{
    while (stack) {
        if (stack && isope(stack->data, arg2)) {
            y[var_y] = stack->data;
            stack = pop(stack);
        } else
            stack = pop(stack);
        ++var_y;
    }
    return (y);
}

char *polish(char const *str, char const *arg2)
{
    linked_list_t *stack = NULL;
    char *y = malloc(sizeof(char) * my_strlen(str) * 2);
    int var_y = 0;
    int bool = 0;
    int i = 0;

    for (int g = 0; g < my_strlen(str) * 2; ++g)
        y[g] = 0;
    for (int i = 0; i < my_strlen(str); ++i)
        y[i] = 0;
    stack = factory(arg2[0], stack);
    if (str[0] == arg2[3]) {
        y[var_y] = str[i++];
        for (; isnum(str[i]); ++i)
            y[var_y++] = str[i];
        y[var_y++] = '_';
    }
    for (i; i < my_strlen(str); ++i) {
        if ((i > 0 && str[i - 1] == arg2[0] && str[i] == arg2[3]) ||
        i > 0 && isope(str[i - 1], arg2) && str[i] == arg2[3]) {
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
        str[i] == arg2[0] ? stack = factory(str[i], stack) : stack;
        if (isope(str[i], arg2) && stack) {
            while (isope(stack->data, arg2) && prio(str[i], stack, arg2)) {
                y[var_y++] = stack->data;
                stack = pop(stack);
            }
            y[var_y++] = ' ';
            stack = factory(str[i], stack);
        }
        if (str[i] == arg2[1]) {
            for (; stack->data != arg2[0]; stack = pop(stack))
                y[var_y++] = stack->data;
            stack = pop(stack);
        }
    }
    return (unstack(stack, var_y, y, arg2));
}
