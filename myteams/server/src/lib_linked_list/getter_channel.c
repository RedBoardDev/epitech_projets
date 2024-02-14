/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** getter_channel.c
*/

#include "../../include/teams.h"

channel_t *get_channel_by_uuid(node_t *channel_list, char *check_uuid)
{
    channel_t *current;
    node_t *current_node = channel_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return current;
        }
        current_node = current_node->next;
    }
    return NULL;
}

node_t *get_channel_per_team(node_t *channel_list, char *uuid_team)
{
    channel_t *current;
    node_t *connected_channel_list = NULL;

    while (channel_list != NULL) {
        current = channel_list->data;
        if (strcmp(current->uuid_team, uuid_team) == 0) {
            channel_t *channel = malloc(sizeof(channel_t));
            channel->uuid = current->uuid;
            channel->name = current->name;
            channel->uuid_team = uuid_team;
            connected_channel_list =
            push_begin(connected_channel_list, channel);
        }
        channel_list = channel_list->next;
    }
    return connected_channel_list;
}
