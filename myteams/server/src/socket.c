/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** socket.c
*/

#include "../include/teams.h"

void close_client_socket(teams_t *teams)
{
    if (teams->clients[teams->iterator].socket != 0)
        close(teams->clients[teams->iterator].socket);
    teams->clients[teams->iterator].socket = 0;
    teams->clients[teams->iterator].user = NULL;
    teams->clients[teams->iterator].uses.use_team_uuid = NULL;
    teams->clients[teams->iterator].uses.use_channel_uuid = NULL;
    teams->clients[teams->iterator].uses.use_thread_uuid = NULL;
}
