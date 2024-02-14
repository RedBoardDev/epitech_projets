/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** getter_team.c
*/

#include "../../include/teams.h"

team_t *get_team_by_uuid(node_t *team_list, char *check_uuid)
{
    team_t *current;
    node_t *current_node = team_list;

    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return current;
        }
        current_node = current_node->next;
    }
    return NULL;
}

node_t *get_uuid_users_on_team_by_uuid(node_t *team_list, char *check_uuid)
{
    team_t *current;

    while (team_list != NULL) {
        current = team_list->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return current->uuid_users;
        }
    }
    return NULL;
}

bool check_actual_team_contain_user_uuid(teams_t *teams, char *check_uuid)
{
    uuid_users_t *current;
    team_t *team = get_team_by_uuid(teams->team,
    teams->clients[teams->iterator].uses.use_team_uuid);
    node_t *uuid_users = team->uuid_users;

    while (uuid_users != NULL) {
        current = uuid_users->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return true;
        }
        uuid_users = uuid_users->next;
    }
    return false;
}
