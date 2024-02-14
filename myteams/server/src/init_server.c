/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** init_server.c
*/

#include "../include/teams.h"

void init_server_socket(int port, teams_t *teams)
{
    int opt = true;

    teams->server.port = port;
    teams->server.socket = socket(AF_INET , SOCK_STREAM , 0);
    setsockopt(teams->server.socket, SOL_SOCKET, SO_REUSEADDR,
    (char *)&opt, sizeof(opt));
    teams->server.address.sin_family = AF_INET;
    teams->server.address.sin_addr.s_addr = INADDR_ANY;
    teams->server.address.sin_port = htons(teams->server.port);
    bind(teams->server.socket, (struct sockaddr *)&teams->server.address,
    sizeof(teams->server.address));
}

void init_clients(teams_t *teams)
{
    teams->private_message = NULL;
    teams->user = NULL;
    teams->channel = NULL;
    teams->comment = NULL;
    teams->team = NULL;
    teams->thread = NULL;
    for (size_t i = 0; i < MAX_USERRR; ++i) {
        teams->clients[i].socket = 0;
        teams->clients[i].user = NULL;
        teams->clients[i].uses.use_team_uuid = NULL;
        teams->clients[i].uses.use_channel_uuid = NULL;
        teams->clients[i].uses.use_thread_uuid = NULL;
    }
}
