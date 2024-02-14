/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** evalexpr_martin.c
*/

#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"

char getope(char o)
{
    if (o == '+')
        return ('+');
    if (o == '-')
        return ('-');
    if (o == '*')
        return ('*');
    if (o == '/')
        return ('/');
    if (o == '%')
        return ('%');
}

int switch_ope(char ope, int result, int nb1, int nb2)
{
    switch (ope) {
    case '+':
        result = nb1 + nb2;
        break;
    case '-':
        result = nb1 - nb2;
        break;
    case '*':
        result = nb1 * nb2;
        break;
    case '/':
        result = nb1 / nb2;
        break;
    case '%':
        result = nb1 % nb2;
        break;
    default :
        my_putstr("Invalid\n");
    }
    return (result);
}

char *while_isnum(int *buffer, char *y, int *i)
{
    while (isnum(y[*i])) {
            *buffer *= 10;
            *buffer += y[*i] - 48;
            *i += 1;
        }
    return y;
}

int eval_expr(char *str)
{
    list_calcul_t *stack_temp = NULL;
    char *y = polish(str);
    int result = 0;
    int buffer = 0;
    int nb1 = 0;
    int nb2 = 0;

    for (int i = 0; y[i] != '\0'; ++i, buffer = 0) {
        y = while_isnum(&buffer, y, &i);
        if (y[i] == '_')
            buffer = buffer * -1;
        buffer != 0 ? stack_temp = factory_calc(buffer, stack_temp) : 0;
        if (isope(y[i])) {
            result = switch_ope(getope(y[i]), result, nb1 = (stack_temp =
            pop_int(stack_temp))->data, nb2 = stack_temp->data);
            stack_temp = factory_calc(result, stack_temp = pop_int(stack_temp));
        }
    }
    free(y);
    result = stack_temp->data;
    stack_temp = pop_int(stack_temp);
    return (result);
}

int main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
