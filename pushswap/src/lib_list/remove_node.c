/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** remove_node.c
*/

#include "../../include/pushswap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void remove_element(list_t *list)
{
    list->prev->next = list->next;
    list->next->prev = list->prev;
    free(list);
}

void remove_end_list(list_t *list)
{
    if (list->next != list)
        remove_element(list->prev);
}

void remove_beginning_list(list_t *list)
{
    if (list->prev != list)
        remove_element(list->next);
}
