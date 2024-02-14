/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** getter_user.c
*/

#include "../../include/teams.h"

bool check_if_user_is_connected(t_client *clients, char *uuid)
{
    for (int i = 0; i < MAX_USERRR; ++i) {
        if (clients[i].user == NULL) continue;
        if (strcmp(clients[i].user->uuid, uuid) == 0)
            return true;
    }
    return false;
}

user_t *get_user_by_uuid(node_t *user_list, char *check_uuid)
{
    user_t *current;
    node_t *current_node = user_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return current;
        }
        current_node = current_node->next;
    }
    return NULL;
}

user_t *get_user_by_username(node_t *user_list, char *username)
{
    user_t *current;
    node_t *current_node = user_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->username, username) == 0) {
            return current;
        }
        current_node = current_node->next;
    }
    return NULL;
}
