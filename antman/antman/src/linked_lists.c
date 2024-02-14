/*
** EPITECH PROJECT, 2021
** antman
** File description:
** linked_lists.c
*/

#include "../include/antman.h"
#include "../include/my.h"

list_t *factory(int data, list_t *new_list)
{
    list_t *node = malloc(sizeof(list_t));
    node->data = data;
    node->next = new_list;
    return (node);
}

list_t *pop(list_t *stack)
{
    list_t *tmp = stack->next;

    if (stack) {
        free(stack);
        return (tmp);
    }
}
