/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** general_function.c
*/

#include "../../include/pushswap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

list_t *init_root_list(void)
{
    list_t *root = malloc(sizeof(*root));

    if (root != NULL) {
        root->prev = root;
        root->next = root;
    }
    return (root);
}

list_t *get_first_node(list_t *list)
{
    if (list->next != list)
        return (list->next);
    else
        return (NULL);
}

list_t *get_second_node(list_t *list)
{
    if (list->next->next != list)
        return (list->next->next);
    else
        return (NULL);
}

list_t *get_last_node(list_t *list)
{
    if (list->prev != list)
        return (list->prev);
    else
        return (NULL);
}
