/*
** EPITECH PROJECT, 2022
** server
** File description:
** list.c
*/

#include "../../include/teams.h"

// send team_uuid~team_name~team_description
static void send_teams_list(teams_t *teams)
{
    team_t *current;
    node_t *current_node;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);
    current_node = teams->team;
    while (current_node != NULL) {
        current = current_node->data;
        ret = my_strcat(ret, current->uuid);
        ret = my_strcat(ret, "~");
        ret = my_strcat(ret, current->name);
        ret = my_strcat(ret, "~");
        ret = my_strcat(ret, current->description);
        ret = my_strcat(ret, "|");
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "160 %s\r\n", ret);
}

// send channel_uuid~channel_name~channel_description
static void send_channels_list(teams_t *teams, char *team_uuid)
{
    channel_t *current;node_t *current_node;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);

    if (check_actual_team_contain_user_uuid(teams,
    teams->clients[teams->iterator].user->uuid) == false) {
        dprintf(teams->clients[teams->iterator].socket, "801\r\n");
        return;
    }
    current_node = teams->channel;
    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid_team, team_uuid) == 0) {
            ret = my_strcat(ret, current->uuid);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->name);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->description);
            ret = my_strcat(ret, "|");
        }
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "161 %s\r\n", ret);
}

// send thread_uuid~user_uuid~thread_timestamp~thread_title~thread_body
static void send_threads_list(teams_t *teams, char *channel_uuid)
{
    char tmp[50];thread_t *current;node_t *current_node;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);
    if (check_actual_team_contain_user_uuid(teams,
    teams->clients[teams->iterator].user->uuid) == false) {
        dprintf(teams->clients[teams->iterator].socket, "801\r\n");return;
    }
    current_node = teams->thread;
    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid_channel, channel_uuid) == 0) {
            ret = my_strcat(ret, current->uuid);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->uuid_author);
            ret = my_strcat(ret, "~");sprintf(tmp, "%ld", current->timestamp);
            ret = my_strcat(ret, tmp);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->name);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->body);ret = my_strcat(ret, "|");
        }
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "162 %s\r\n", ret);
}

// send thread_uuid~user_uuid~reply_timestamp~reply_body
static void send_comments_list(teams_t *teams, char *thread_uuid)
{
    char tmp[50];comment_t *current;node_t *current_node;
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);
    if (check_actual_team_contain_user_uuid(teams,
    teams->clients[teams->iterator].user->uuid) == false) {
        dprintf(teams->clients[teams->iterator].socket, "801\r\n");return;
    }
    current_node = teams->comment;
    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid_thread, thread_uuid) == 0) {
            ret = my_strcat(ret, current->uuid_thread);
            ret = my_strcat(ret, "~");ret = my_strcat(ret, current->uuid_user);
            ret = my_strcat(ret, "~");sprintf(tmp, "%ld", current->timestamp);
            ret = my_strcat(ret, tmp);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->message);ret = my_strcat(ret, "|");
        }
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "163 %s\r\n", ret);
}

void cmd_list(teams_t *teams, char **command, int nbr_args)
{
    char *use_team_uuid = teams->clients[teams->iterator].uses.use_team_uuid;
    char *use_channel_uuid =
    teams->clients[teams->iterator].uses.use_channel_uuid;
    char *use_thread_uuid =
    teams->clients[teams->iterator].uses.use_thread_uuid;

    if (use_team_uuid == NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL)
        return send_teams_list(teams);
    if (use_team_uuid != NULL && use_channel_uuid == NULL
    && use_thread_uuid == NULL)
        return send_channels_list(teams, use_team_uuid);
    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid == NULL)
        return send_threads_list(teams, use_channel_uuid);
    if (use_team_uuid != NULL && use_channel_uuid != NULL
    && use_thread_uuid != NULL)
        return send_comments_list(teams, use_thread_uuid);
    send_response(teams->clients[teams->iterator].socket, "%s\r\n",
    "365 Create command failed");
}
