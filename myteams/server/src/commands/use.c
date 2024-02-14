/*
** EPITECH PROJECT, 2022
** server
** File description:
** use.c
*/

#include "../../include/teams.h"

void cmd_use_0(teams_t *teams, char **command, int nbr_args)
{
    teams->clients[teams->iterator].uses.use_team_uuid = NULL;
    teams->clients[teams->iterator].uses.use_channel_uuid = NULL;
    teams->clients[teams->iterator].uses.use_thread_uuid = NULL;
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "140 Set the command context to undefined successed");
}

void cmd_use_1(teams_t *teams, char **command, int nbr_args)
{
    char *team_uuid = command[1];
    team_t *team = get_team_by_uuid(teams->team, team_uuid);

    if (team == NULL) {
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to team failed");
    }
    free_if_not_null(teams->clients[teams->iterator].uses.use_team_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_channel_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_thread_uuid);
    teams->clients[teams->iterator].uses.use_team_uuid = team_uuid;
    teams->clients[teams->iterator].uses.use_channel_uuid = NULL;
    teams->clients[teams->iterator].uses.use_thread_uuid = NULL;
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "140 Set the command context to team successed");
}

void cmd_use_2(teams_t *teams, char **command, int nbr_args)
{
    char *team_uuid = command[1];
    char *channel_uuid = command[2];
    team_t *team = get_team_by_uuid(teams->team, team_uuid);
    channel_t *channel = get_channel_by_uuid(teams->channel, channel_uuid);

    if (team == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to team failed");
    if (channel == NULL || strcmp(channel->uuid_team, team_uuid) != 0)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to channel failed");
    free_if_not_null(teams->clients[teams->iterator].uses.use_team_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_channel_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_thread_uuid);
    teams->clients[teams->iterator].uses.use_team_uuid = team_uuid;
    teams->clients[teams->iterator].uses.use_channel_uuid = channel_uuid;
    teams->clients[teams->iterator].uses.use_thread_uuid = NULL;
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "140 Set the command context to team and channel successed");
}

int cmd_use_3_next(teams_t *teams, char **command)
{
    team_t *team = get_team_by_uuid(teams->team, command[1]);
    channel_t *channel = get_channel_by_uuid(teams->channel, command[2]);
    thread_t *thread = get_thread_by_uuid(teams->thread, command[3]);

    if (team == NULL) {
        send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to team failed");
        return 0;
    }
    if (channel == NULL || strcmp(channel->uuid_team, command[1]) != 0) {
        send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to channel failed");
        return 0;
    }
    if (thread == NULL || strcmp(thread->uuid_channel, command[2]) != 0) {
        send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "340  Set the command context to thread failed");
        return 0;
    }
    return 1;
}

void cmd_use_3(teams_t *teams, char **command, int nbr_args)
{
    char *team_uuid = command[1];
    char *channel_uuid = command[2];
    char *thread_uuid = command[3];

    if (cmd_use_3_next(teams, command) == 0)
        return;
    free_if_not_null(teams->clients[teams->iterator].uses.use_team_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_channel_uuid);
    free_if_not_null(teams->clients[teams->iterator].uses.use_thread_uuid);
    teams->clients[teams->iterator].uses.use_team_uuid = team_uuid;
    teams->clients[teams->iterator].uses.use_channel_uuid = channel_uuid;
    teams->clients[teams->iterator].uses.use_thread_uuid = thread_uuid;
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "140 Set the command context to team, channel and thread successed");
}
