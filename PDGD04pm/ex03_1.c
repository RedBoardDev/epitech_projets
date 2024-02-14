/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD04pm-thomas.ott
** File description:
** exo3_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"
#include "stack.h"

void stack_clear(stack_t *stack_ptr)
{
    return (list_clear(stack_ptr));
}

void *stack_top(stack_t stack)
{
    return (list_get_elem_at_front(stack));
}
