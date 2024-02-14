/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** login.c
*/

#include "../../include/teams.h"

user_t *creat_user_node(user_t user_node)
{
    user_t *new_user = malloc(sizeof(user_t));

    new_user->uuid = user_node.uuid;
    new_user->username = strdup(user_node.username);
    free(user_node.username);
    return new_user;
}

void cmd_login_next(teams_t *teams, char **command,
int nbr_args, user_t *new_user)
{
    new_user = creat_user_node((user_t){generate_uuid(), command[1]});
    teams->user = push_begin(teams->user, new_user);
    teams->clients[teams->iterator].user = new_user;
    server_event_user_created(new_user->uuid, new_user->username);
}

void cmd_login_2(teams_t *teams)
{
    dprintf(teams->clients[teams->iterator].socket, "110 %s~%s\r\n",
    teams->clients[teams->iterator].user->uuid,
    teams->clients[teams->iterator].user->username);
    send_event_message_to_all(teams, "990 %s~%s\r\n",
    teams->clients[teams->iterator].user->uuid,
    teams->clients[teams->iterator].user->username);
}

void cmd_login(teams_t *teams, char **command, int nbr_args)
{
    user_t *new_user = NULL;
    user_t *user = get_user_by_username(teams->user, command[1]);

    if (user != NULL) {
        teams->clients[teams->iterator].user = user;
    } else
        cmd_login_next(teams, command, nbr_args, new_user);
    server_event_user_logged_in(teams->clients[teams->iterator].user->uuid);
    cmd_login_2(teams);
}
