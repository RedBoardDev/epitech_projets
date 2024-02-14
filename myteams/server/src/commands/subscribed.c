/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** subscribed.c
*/

#include "../../include/teams.h"

void cmd_subscribed_0(teams_t *teams, char **command, int nbr_args)
{
    team_t *current;
    node_t *current_node;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);

    if (teams->user == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "333 Users list failed\r\n");
    current_node = teams->team;
    while (current_node != NULL) {
        current = current_node->data;
        if (check_subscribe_user_on_team(current->uuid_users,
        teams->clients[teams->iterator].user->uuid)) {
            ret = my_strcat(ret, current->uuid);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->name);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->description);
            ret = my_strcat(ret, "|");
        }
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "133 %s\r\n", ret);
}

void cmd_subscribed_1(teams_t *teams, char **command, int nbr_args)
{
    uuid_users_t *current;user_t *user_current;node_t *current_node = NULL;
    team_t *current_team = get_team_by_uuid(teams->team, command[1]);
    bool connected = false;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);

    if (current_team == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "333 Team not found\r\n");
    current_node = current_team->uuid_users;
    while (current_node != NULL) {
        current = current_node->data;
        user_current = get_user_by_uuid(teams->user, current->uuid);
        if (user_current == NULL) continue;
        connected = check_if_user_is_connected(teams->clients,
        user_current->uuid);
        ret = my_strcat(ret, user_current->uuid);ret = my_strcat(ret, "~");
        ret = my_strcat(ret, user_current->username);ret = my_strcat(ret, "~");
        ret = my_strcat(ret, connected ? "true" : "false");
        ret = my_strcat(ret, "|");current_node = current_node->next;
    }dprintf(teams->clients[teams->iterator].socket, "233 %s\r\n", ret);
}
