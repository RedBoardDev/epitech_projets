/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** add_list.c
*/

#include "../../include/teams.h"

static node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

node_t *push_begin(node_t *head, void *data)
{
    node_t *newnode_t = create_node(data);
    newnode_t->next = head;
    return newnode_t;
}

node_t *push_end(node_t *head, void *data)
{
    node_t *current;
    node_t *newnode_t = create_node(data);

    if (head == NULL) return newnode_t;
    current = head;
    while (current->next != NULL) current = current->next;
    current->next = newnode_t;
    return head;
}
