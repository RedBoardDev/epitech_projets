/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo1_0.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int count = 0;
    list_t current = list;

    while (current != NULL) {
        ++count;
        current = current->next;
    }
    return (count);
}

bool list_is_empty(list_t list)
{
    return (!list ? true : false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t current = list;

    while (current != NULL) {
        val_disp(current->value);
        current = current->next;
    }
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t current = malloc(sizeof(*current));

    if (!current) {
        free(current);
        return (false);
    }
    current->value = elem;
    current->next = (*front_ptr);
    (*front_ptr) = current;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t current = malloc(sizeof(*current));
    list_t tmp = (*front_ptr);

    if (!current)
        return (false);
    if (!(*front_ptr)) {
        free(current);
        return (list_add_elem_at_front(front_ptr, elem));
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    current->value = elem;
    current->next = NULL;
    tmp->next = current;
    return (true);
}
