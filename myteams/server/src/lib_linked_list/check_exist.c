/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** check_exist.c
*/

#include "../../include/teams.h"

bool check_if_channel_exist(node_t *channel_list, char *channel_name)
{
    channel_t *current;
    node_t *current_node = channel_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->name, channel_name) == 0) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

bool check_if_team_exist(node_t *team_list, char *team_name)
{
    team_t *current;
    node_t *current_node = team_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->name, team_name) == 0) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

bool check_if_thread_exist(node_t *thread_list, char *thread_name)
{
    thread_t *current;
    node_t *current_node = thread_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->name, thread_name) == 0) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}
