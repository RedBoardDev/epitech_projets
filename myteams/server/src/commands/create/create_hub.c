/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_2_hub.c
*/

#include "../../../include/teams.h"

static void cmd_create_next(teams_t *teams, char **command, int nbr_args)
{
    char *use_team_uuid = teams->clients[teams->iterator].uses.use_team_uuid;
    char *use_channel_uuid =
    teams->clients[teams->iterator].uses.use_channel_uuid;
    char *use_thread_uuid =
    teams->clients[teams->iterator].uses.use_thread_uuid;

    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid == NULL) {
        cmd_create_thread(teams, command, use_channel_uuid);
        return;
    }
    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid != NULL) {
        cmd_create_reply(teams, command, use_thread_uuid, use_team_uuid);
        return;
    }
}

void cmd_create_hub(teams_t *teams, char **command, int nbr_args)
{
    char *use_team_uuid = teams->clients[teams->iterator].uses.use_team_uuid;
    char *use_channel_uuid =
    teams->clients[teams->iterator].uses.use_channel_uuid;
    char *use_thread_uuid =
    teams->clients[teams->iterator].uses.use_thread_uuid;

    if (use_team_uuid == NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL) {
        cmd_create_team(teams, command);
        return;
    }
    if (use_team_uuid != NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL) {
        cmd_create_channel(teams, command, use_team_uuid);
        return;
    }
    cmd_create_next(teams, command, nbr_args);
}
