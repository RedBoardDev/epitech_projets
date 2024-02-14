/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo0_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "int_list.h"

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_list_t tmp_front = (*front_ptr), tmp_end;
    if (position == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    int_list_t current = malloc(sizeof(*current));
    if (current == NULL || position > int_list_get_size(*front_ptr)) {
        free(current);
        return (false);
    }
    for (unsigned int i = 1; i < position; ++i) {
        tmp_front = tmp_front->next;
        if (!tmp_front) {
            free(current);
            return (false);
        }
    }
    tmp_end = tmp_front->next;
    current->value = elem;
    current->next = tmp_end;
    tmp_front->next = current;
    return (true);
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t current = list;

    if (!list)
        return (0);
    while (current->next != NULL) {
        current = current->next;
    }
    return (current->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int i = 0;
    int_list_t current = list;

    if (!list)
        return (0);
    while (i < position) {
        current = current->next;
        i++;
        if (!current)
            return (0);
    }
    return (current->value);
}
