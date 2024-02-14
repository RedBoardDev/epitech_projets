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
#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return (list_get_size(stack));
}

bool stack_is_empty(stack_t stack)
{
    return (list_is_empty(stack));
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return (list_add_elem_at_front(stack_ptr, elem));
}

bool stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_front(stack_ptr));
}
