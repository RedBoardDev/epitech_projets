/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** unsubscribe.c
*/

#include "../../include/teams.h"

void cmd_unsubscribe(teams_t *teams, char **command, int nbr_args)
{
    char *team_uuid = command[1];
    team_t *current_team = get_team_by_uuid(teams->team, team_uuid);

    if (current_team == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "332 Team not found");
    if (check_subscribe_user_on_team(current_team->uuid_users,
    teams->clients[teams->iterator].user->uuid) == true) {
        current_team->uuid_users = remove_node_by_uuid(current_team->uuid_users,
        teams->clients[teams->iterator].user->uuid);
    }
    dprintf(teams->clients[teams->iterator].socket, "134 %s~%s\r\n",
    teams->clients[teams->iterator].user->uuid, team_uuid);
    server_event_user_unsubscribed(team_uuid,
    teams->clients[teams->iterator].user->uuid);
}
