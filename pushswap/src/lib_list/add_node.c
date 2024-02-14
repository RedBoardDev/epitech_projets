/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** add_node.c
*/

#include "../../include/pushswap.h"
#include <string.h>
#include <stdlib.h>

void add_end_list(list_t *list, int nbr)
{
    list_t *node = malloc(sizeof(*node));

    if (node != NULL) {
        node->data = nbr;
        node->prev = list->prev;
        node->next = list;
        list->prev->next = node;
        list->prev = node;
    }
}

void add_beginning_list(list_t *list, int nbr)
{
    list_t *node = malloc(sizeof(*node));

    if (node != NULL) {
        node->data = nbr;
        node->prev = list;
        node->next = list->next;
        list->next->prev = node;
        list->next = node;
    }
}
