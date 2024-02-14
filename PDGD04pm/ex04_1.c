/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo4_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"
#include "queue.h"

bool queue_pop(queue_t *queue_ptr)
{
    return (list_del_elem_at_position(queue_ptr, 1));
}

void queue_clear(queue_t *queue_ptr)
{
    return (list_clear(queue_ptr));
}

void *queue_front(queue_t queue)
{
    return (list_get_elem_at_position(queue, 1));
}
