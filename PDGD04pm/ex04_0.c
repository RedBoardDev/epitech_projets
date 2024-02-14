/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo4_0.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"
#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return (list_get_size(queue));
}

bool queue_is_empty(queue_t queue)
{
    return (list_is_empty(queue));
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return (list_add_elem_at_back(queue_ptr, elem));
}
