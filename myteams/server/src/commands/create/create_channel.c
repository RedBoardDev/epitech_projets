/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_team.c
*/

#include "../../../include/teams.h"

int cmd_create_channel(teams_t *teams, char **command, char *use_team_uuid)
{
    char *new_uuid;

    if (check_if_channel_exist(teams->channel, command[1]))
        return dprintf(teams->clients[teams->iterator].socket, "800\r\n");
    if (check_actual_team_contain_user_uuid(teams,
        teams->clients[teams->iterator].user->uuid) == false)
        return dprintf(teams->clients[teams->iterator].socket, "801\r\n");
    new_uuid = generate_uuid();
    teams->channel = push_begin(teams->channel, create_channel_node((
    channel_t){new_uuid, use_team_uuid, command[1], command[2]}));
    server_event_channel_created(use_team_uuid, new_uuid, command[1]);
    dprintf(teams->clients[teams->iterator].socket, "151 %s~%s~%s|\r\n",
    new_uuid, command[1], command[2]);
    send_event_message_to_team(teams, "993 %s~%s~%s\r\n",
    new_uuid, command[1], command[2]);
    return 0;
}
