/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday11-thomas.ott
** File description:
** my_params_to_list.c
*/

#include <stdio.h>
#include "include/mylist.h"

linked_list_t *factory(void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    node->data = data;
    node->next = NULL;
    return (node);
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;
    linked_list_t *buffer;

    list = NULL;
    for (int i = 0; i < ac; ++i) {
        buffer = factory(av[i]);
        buffer->next = list;
        list = buffer;
    }
    return list;
}
