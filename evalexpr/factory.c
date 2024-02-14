/*
** EPITECH PROJECT, 2021
** B-CPE-101-MLH-1-1-evalexpr-martin.d-herouville
** File description:
** factory.c
*/

#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"

linked_list_t *factory(char data, linked_list_t *new_list)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    node->data = data;
    node->next = new_list;
    return (node);
}

list_calcul_t *factory_calc(int data, list_calcul_t *new_list)
{
    list_calcul_t *node = malloc(sizeof(list_calcul_t));
    node->data = data;
    node->next = new_list;
    return (node);
}

linked_list_t *pop(linked_list_t *stack)
{
    linked_list_t *tmp = stack->next;

    if (stack) {
        free(stack);
        return (tmp);
    }
}

list_calcul_t *pop_int(list_calcul_t *stack)
{
    list_calcul_t *tmp = stack->next;

    if (stack) {
        free(stack);
        return (tmp);
    }
}
