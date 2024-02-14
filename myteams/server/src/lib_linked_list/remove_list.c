/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** remove_list.c
*/

#include "../../include/teams.h"

node_t *pop_begin(node_t *head)
{
    if (head == NULL) return NULL;
    node_t *firstnode_t = head;
    head = firstnode_t->next;
    free(firstnode_t);
    return head;
}

node_t *pop_end(node_t *head)
{
    node_t *current;

    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    current = head;
    while (current->next->next != NULL) current = current->next;
    free(current->next);
    current->next = NULL;
    return head;
}

void remove_list(node_t *head)
{
    while ((head = pop_begin(head)) != NULL);
}
