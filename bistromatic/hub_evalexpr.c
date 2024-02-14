/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** hub_evalexpr.c
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

int hub_evalexpr(char *av1, char *av2, char *expr, unsigned int size)
{
    int count = 0;
    char *result;

    for (int i = 0; expr[i] != '\0'; ++i) {
        count = 0;
        while (isnum(expr[i])) {
            ++count;
            ++i;
        }
        if (count >= 10) {
            my_putstr(eval_expr_inf(av1, av2, expr, size));
            return (0);
        }
    }
    my_put_nbr(eval_expr_int(expr));
    return (0);
}
