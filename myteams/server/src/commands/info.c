/*
** EPITECH PROJECT, 2022
** server
** File description:
** info.c
*/

#include "../../include/teams.h"

// send user_uuid~user_name~user_status
static void send_user_info(teams_t *teams)
{
    bool connected = check_if_user_is_connected(teams->clients,
    teams->clients[teams->iterator].user->uuid);

    dprintf(teams->clients[teams->iterator].socket, "170 %s~%s~%s\r\n",
    teams->clients[teams->iterator].user->uuid,
    teams->clients[teams->iterator].user->username,
    connected ? "true" : "false");
}

// send team_uuid~team_name~team_description
static void send_team_info(teams_t *teams, char *team_uuid)
{
    team_t *current = get_team_by_uuid(teams->team,
    teams->clients[teams->iterator].uses.use_team_uuid);

    if (current == NULL) {
        dprintf(teams->clients[teams->iterator].socket, "375 Error code\r\n");
        return;
    }
    dprintf(teams->clients[teams->iterator].socket, "171 %s~%s~%s\r\n",
    current->uuid, current->name, current->description);
}

// send channel_uuid~channel_name~channel_description
static void send_channel_info(teams_t *teams, char *channel_uuid)
{
    channel_t *current = get_channel_by_uuid(teams->channel,
    teams->clients[teams->iterator].uses.use_channel_uuid);

    if (check_actual_team_contain_user_uuid(teams,
    teams->clients[teams->iterator].user->uuid) == false) {
        dprintf(teams->clients[teams->iterator].socket, "801\r\n");
        return;
    }
    if (current == NULL) {
        dprintf(teams->clients[teams->iterator].socket, "375 Error code\r\n");
        return;
    }
    dprintf(teams->clients[teams->iterator].socket, "172 %s~%s~%s\r\n",
    current->uuid, current->name, current->description);
}

static void send_thread_info(teams_t *teams, char *channel_uuid)
{
    thread_t *current = get_thread_by_uuid(teams->thread,
    teams->clients[teams->iterator].uses.use_thread_uuid);

    if (check_actual_team_contain_user_uuid(teams,
    teams->clients[teams->iterator].user->uuid) == false) {
        dprintf(teams->clients[teams->iterator].socket, "801\r\n");
        return;
    }
    if (current == NULL) {
        dprintf(teams->clients[teams->iterator].socket, "375 Error code\r\n");
        return;
    }
    dprintf(teams->clients[teams->iterator].socket, "173 %s~%s~%ld~%s~%s\r\n",
    current->uuid, current->uuid_author, current->timestamp,
    current->name, current->body);
}

void cmd_info(teams_t *teams, char **command, int nbr_args)
{
    char *use_team_uuid = teams->clients[teams->iterator].uses.use_team_uuid;
    char *use_channel_uuid =
    teams->clients[teams->iterator].uses.use_channel_uuid;
    char *use_thread_uuid =
    teams->clients[teams->iterator].uses.use_thread_uuid;

    if (use_team_uuid == NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL)
        return send_user_info(teams);
    if (use_team_uuid != NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL)
        return send_team_info(teams, use_team_uuid);
    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid == NULL)
        return send_channel_info(teams, use_channel_uuid);
    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid != NULL)
        return send_thread_info(teams, use_channel_uuid);
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "365 Create command failed");
}
