/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_team.c
*/

#include "../../../include/teams.h"

int cmd_create_team(teams_t *teams, char **command)
{
    char *new_uuid;

    if (check_if_team_exist(teams->team, command[1]))
        return dprintf(teams->clients[teams->iterator].socket, "800\r\n");
    new_uuid = generate_uuid();
    teams->team = push_begin(teams->team, create_team_node((team_t)
    {new_uuid, NULL, command[1], command[2]}));
    server_event_team_created(new_uuid,
    command[1], teams->clients[teams->iterator].user->uuid);
    dprintf(teams->clients[teams->iterator].socket, "150 %s~%s~%s|\r\n",
    new_uuid, command[1], command[2]);
    send_event_message_to_all(teams, "992 %s~%s~%s|\r\n",
    new_uuid, command[1], command[2]);
    return 0;
}
