/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo0_2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t* front_ptr)
{
    int_list_t current = (*front_ptr);

    if (!*front_ptr)
        return (false);
    (*front_ptr) = (*front_ptr)->next;
    free(current);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t current = (*front_ptr);

    if (!*front_ptr)
        return (false);
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    unsigned int i = 1;
    int_list_t tmp_front = (*front_ptr);
    int_list_t tmp_end;

    if (!*front_ptr)
        return (false);
    if (position == 0)
        return (int_list_del_elem_at_front(front_ptr));
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

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t tmp_front = (*front_ptr);

    while ((*front_ptr) != NULL) {
        tmp_front = (*front_ptr);
        (*front_ptr) = (*front_ptr)->next;
        free(tmp_front);
    }
}
