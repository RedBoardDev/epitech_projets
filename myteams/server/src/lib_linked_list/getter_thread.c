/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** getter_thread.c
*/

#include "../../include/teams.h"

thread_t *get_thread_by_uuid(node_t *thread_list, char *check_uuid)
{
    thread_t *current;
    node_t *current_node = thread_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return current;
        }
        current_node = current_node->next;
    }
    return NULL;
}
