/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo1_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int pos)
{
    list_t tmp_front = (*front_ptr), tmp_end;
    if (pos == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    list_t current = malloc(sizeof(*current));
    if (current == NULL || pos > int_list_get_size(*front_ptr)) {
        free(current);
        return (false);
    }
    for (unsigned int i = 1; i < pos; ++i) {
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

void *list_get_elem_at_front(list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t current = list;

    if (!list)
        return (0);
    while (current->next != NULL) {
        current = current->next;
    }
    return (current->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int i = 1;
    list_t current = list;

    if (!list)
        return (0);
    while (i < position) {
        current = current->next;
        i++;
        if (!current)
            return (false);
    }
    return (current->value);
}
