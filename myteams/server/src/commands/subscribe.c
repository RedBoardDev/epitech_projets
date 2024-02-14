/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** subscribe.c
*/

#include "../../include/teams.h"

void cmd_subscribe(teams_t *teams, char **command, int nbr_args)
{
    uuid_users_t *current_node = malloc(sizeof(uuid_users_t));
    char *team_uuid = command[1];
    team_t *current_team = get_team_by_uuid(teams->team, team_uuid);

    if (current_team == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "332 Team not found\r\n");
    if (check_subscribe_user_on_team(current_team->uuid_users,
    teams->clients[teams->iterator].user->uuid) == false) {
        current_node->uuid = strdup(teams->clients[teams->iterator].user->uuid);
        current_team->uuid_users =
        push_begin(current_team->uuid_users, current_node);
    }
    dprintf(teams->clients[teams->iterator].socket, "132 %s~%s|\r\n",
    teams->clients[teams->iterator].user->uuid, team_uuid);
    server_event_user_subscribed(team_uuid,
    teams->clients[teams->iterator].user->uuid);
}
