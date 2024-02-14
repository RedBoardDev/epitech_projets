/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** user.c
*/

#include "../../include/teams.h"

void cmd_user(teams_t *teams, char **command, int nbr_args)
{
    user_t *current = get_user_by_uuid(teams->user, command[1]);
    bool connected = true;

    if (current == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "321 User details failed");
    connected = check_if_user_is_connected(teams->clients,
    current->uuid);
    dprintf(teams->clients[teams->iterator].socket, "121 %s~%s~%s\r\n",
    current->uuid, current->username, connected ? "true" : "false");
}
