/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** eval_expr.c
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

char getope(char o, char const *arg2)
{
    if (o == arg2[2])
        return ('+');
    if (o == arg2[3])
        return ('-');
    if (o == arg2[4])
        return ('*');
    if (o == arg2[5])
        return ('/');
    if (o == arg2[6])
        return ('%');
}

char *eval_expr(char *av1, char *av2, char const *expr,
unsigned int size)
{
    list_inf_t *stack_temp = NULL;
    char *y = polish(expr, av2);
    char *result = 0;
    char *buffer;
    char *temp;
    char *nb1;
    char *nb2;
    char ope;
    int j = 0;
    int buff_i = 0;
    int count = 0;

    result = av1;
    for (int i = 0; y[i] != '\0'; ++i, buffer = 0) {
        j = 0;
        count = 0;
        buff_i = i;
        while (isnum(y[i])) {
            ++count;
            ++i;
        }
        buffer = malloc(sizeof(char) * count + 1);
        buffer[count] = '\0';
        i = buff_i;
        while (isnum(y[i])) {
            buffer[j] = y[i];
            i += 1;
            ++j;
        }
        temp = malloc(sizeof(char) * my_strlen(buffer) + 2);
        temp[my_strlen(buffer) + 1] = '\0';
        if (y[i] == '_') {
            temp[0] = '-';
            for (int n = 1; buffer[n - 1] != '\0'; ++n)
                temp[n] = buffer[n - 1];
            buffer = temp;
        }
        if (j > 0)
            stack_temp = factory_inf(buffer, stack_temp);
        if (isope(y[i], av2)) {
            nb1 = stack_temp->data;
            stack_temp = pop_inf(stack_temp);
            nb2 = stack_temp->data;
            result = hub_calcul(nb2, nb1, getope(y[i], av2));
            stack_temp = pop_inf(stack_temp);
            stack_temp = factory_inf(result, stack_temp);
        }
    }
    free(y);
    stack_temp = pop_inf(stack_temp);
    return (result);
}
