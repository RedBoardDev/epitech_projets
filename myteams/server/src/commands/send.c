/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** send.c
*/

#include <time.h>
#include "../../include/teams.h"

static int get_socket_from_uuid_client(teams_t *teams, char *uuid)
{
    int i = 0;

    while (i < MAX_USERRR) {
        if (strcmp(teams->clients[i].user->uuid, uuid) == 0)
            return teams->clients[i].socket;
        ++i;
    }
    return -1;
}

void cmd_send(teams_t *teams, char **command, int nbr_args)
{
    char *uuid;
    user_t *target_user = get_user_by_uuid(teams->user, command[1]);
    char *message = command[2];

    if (target_user == NULL)
        return send_response(teams->clients[teams->iterator].socket,
        "%s\r\n", "330 Error to logout");
    uuid = generate_uuid();
    teams->private_message = push_begin(teams->private_message,
    create_private_message_node((private_message_t)
    {uuid, teams->clients[teams->iterator].user->uuid,
    target_user->uuid, message, time(NULL)}));
    server_event_private_message_sended(
    teams->clients[teams->iterator].user->uuid, target_user->uuid, message);
    dprintf(get_socket_from_uuid_client(teams, target_user->uuid),
    "130 %s~%s\r\n", teams->clients[teams->iterator].user->uuid, message);
}
