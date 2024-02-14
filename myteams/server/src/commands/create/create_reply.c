/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_reply.c
*/

#include <time.h>
#include "../../../include/teams.h"

int cmd_create_reply(teams_t *teams, char **command, char *use_thread_uuid,
char *use_team_uuid)
{
    char *new_uuid;
    time_t new_timestamp;
    char *user_uuid = teams->clients[teams->iterator].user->uuid;

    if (check_actual_team_contain_user_uuid(teams, user_uuid) == false)
        return dprintf(teams->clients[teams->iterator].socket, "801\r\n");
    new_uuid = generate_uuid();
    new_timestamp = time(NULL);
    teams->comment = push_begin(teams->comment, create_comment_node((comment_t){
    new_uuid, user_uuid, use_thread_uuid, command[1], new_timestamp}));
    server_event_reply_created(use_thread_uuid, user_uuid, command[1]);
    dprintf(teams->clients[teams->iterator].socket, "153 %s~%s~%ld~%s~%s|\r\n",
    use_thread_uuid, user_uuid, new_timestamp, command[1], use_team_uuid);
    send_event_message_to_team(teams, "995 %s~%s~%s~%s\r\n",
    use_team_uuid, use_thread_uuid, user_uuid, command[1]);
    return 0;
}
