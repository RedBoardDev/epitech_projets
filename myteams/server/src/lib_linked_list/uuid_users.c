/*
** EPITECH PROJECT, 2022
** server
** File description:
** uuid_users.c
*/

#include "../../include/teams.h"

bool check_subscribe_user_on_team(node_t *uuid_users, char *user_uuid)
{
    uuid_users_t *current_node;
    node_t *current = uuid_users;

    while (current != NULL) {
        current_node = current->data;
        if (strcmp(current_node->uuid, user_uuid) == 0)
            return true;
        current = current->next;
    }
    return false;
}

node_t *remove_node_by_uuid(node_t *head, char *user_uuid)
{
    node_t *current_next = head;
    node_t **previous_node = &head;
    uuid_users_t *current_node;

    while (current_next != NULL) {
        current_node = current_next->data;
        if (strcmp(current_node->uuid, user_uuid) == 0) {
            *previous_node = current_next->next;
            free(current_node);
            free(current_next);
            break;
        }
        previous_node = &current_next->next;
        current_next = current_next->next;
    }
    return head;
}
