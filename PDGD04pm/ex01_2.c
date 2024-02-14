/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo1_2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t current = (*front_ptr);

    if (!*front_ptr)
        return (false);
    (*front_ptr) = (*front_ptr)->next;
    free(current);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t current = (*front_ptr);

    if (!*front_ptr)
        return (false);
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    unsigned int i = 1;
    list_t tmp_front = (*front_ptr);
    list_t tmp_end;

    if (!*front_ptr)
        return (false);
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    while (i < position) {
        tmp_front = tmp_front->next;
        ++i;
        if (!tmp_front)
            return (false);
    }
    tmp_end = tmp_front->next;
    tmp_front->next = tmp_end->next;
    free(tmp_end);
    return (true);
}

void list_clear(list_t *front)
{
    list_t tmp_front = (*front);

    while ((*front) != NULL) {
        tmp_front = (*front);
        (*front) = (*front)->next;
        free(tmp_front);
    }
}
