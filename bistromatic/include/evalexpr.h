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
list_inf_t *factory_inf(char *data, list_inf_t *new_list);
linked_list_t *pop(linked_list_t *stack);
list_inf_t *pop_inf(list_inf_t *stack);
list_calcul_t *factory_calc(int data, list_calcul_t *new_list);
list_calcul_t *pop_int(list_calcul_t *stack);
char *polish(char const *str, char const *arg2);
int isnum(char c);
int isparenthesis(char c, char const *arg2);
int isope(char c, char const *arg2);
int prio(char str, linked_list_t *stack, char const *av2);
char *switch_ope(char ope, char *result, char *av1, char *av2);
int switch_ope_mlsqkfdjsfdq(char ope, int result, int nb1, int nb2);

#endif
