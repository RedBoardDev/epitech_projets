/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** logout.c
*/

#include "../../include/teams.h"

void cmd_logout(teams_t *teams, char **command, int nbr_args)
{
    dprintf(teams->clients[teams->iterator].socket,
    "111 %s~%s\r\n", teams->clients[teams->iterator].user->uuid,
    teams->clients[teams->iterator].user->username);
    server_event_user_logged_out(teams->clients[teams->iterator].user->uuid);
    send_event_message_to_all(teams, "991 %s~%s\r\n",
    teams->clients[teams->iterator].user->uuid,
    teams->clients[teams->iterator].user->username);
    teams->clients[teams->iterator].user = NULL;
    teams->clients[teams->iterator].uses.use_team_uuid = NULL;
    teams->clients[teams->iterator].uses.use_channel_uuid = NULL;
    teams->clients[teams->iterator].uses.use_thread_uuid = NULL;
}
