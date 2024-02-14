/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int count = 0;
    int_list_t current = list;

    while (current != NULL) {
        ++count;
        current = current->next;
    }
    return (count);
}

bool int_list_is_empty(int_list_t list)
{
    return (!list ? true : false);
}

void int_list_dump(int_list_t list)
{
    int_list_t current = list;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t current = malloc(sizeof(*current));

    if (!current) {
        free(current);
        return (false);
    }
    current->value = elem;
    current->next = (*front_ptr);
    (*front_ptr) = current;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t current = malloc(sizeof(*current));
    int_list_t tmp = (*front_ptr);

    if (!current)
        return (false);
    if (!(*front_ptr)) {
        free(current);
        return (int_list_add_elem_at_front(front_ptr, elem));
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    current->value = elem;
    current->next = NULL;
    tmp->next = current;
    return (true);
}
