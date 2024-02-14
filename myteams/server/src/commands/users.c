/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** users.c
*/

#include "../../include/teams.h"

void cmd_users(teams_t *teams, char **command, int nbr_args)
{
    user_t *current;
    node_t *current_node;
    char *ret = malloc(sizeof(char) * 100000);memset(ret, 0, 1);
    bool connected = false;

    if (teams->user == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "320 Users list failed");
    current_node = teams->user;
    while (current_node != NULL) {
        current = current_node->data;
        ret = strcat(ret, current->uuid);ret = strcat(ret, "~");
        ret = strcat(ret, current->username);ret = strcat(ret, "~");
        connected = check_if_user_is_connected(teams->clients,
        current->uuid);
        ret = strcat(ret, connected ? "true" : "false");
        ret = strcat(ret, "|");
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "120 %s\r\n", ret);
}
