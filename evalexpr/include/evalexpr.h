/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** evalexpr.h
*/

#ifndef EVALEXPR_H_
    #define EVALEXPR_H_

#include "structure.h"
#include "my.h"

linked_list_t *factory(char data, linked_list_t *new_list);
list_calcul_t *factory_calc(int data, list_calcul_t *new_list);
char *polish(char *str);
int eval_expr(char *str);
int isnum(char c);
int isparenthesis(char c);
int isope(char c);
int prio(char str, linked_list_t *stack);
linked_list_t *pop(linked_list_t *stack);
list_calcul_t *pop_int(list_calcul_t *stack);

#endif
