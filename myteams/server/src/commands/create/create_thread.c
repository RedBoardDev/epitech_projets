/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_thread.c
*/

#include <time.h>
#include "../../../include/teams.h"

int cmd_create_thread(teams_t *teams, char **command, char *use_channel_uuid)
{
    char *new_uuid;
    time_t new_time;
    char *user_uuid = teams->clients[teams->iterator].user->uuid;
    if (check_if_thread_exist(teams->thread, command[1]))
        return dprintf(teams->clients[teams->iterator].socket, "800\r\n");
    if (check_actual_team_contain_user_uuid(teams, user_uuid) == false)
        return dprintf(teams->clients[teams->iterator].socket, "801\r\n");
    new_uuid = generate_uuid();
    new_time = time(NULL);
    teams->thread = push_begin(teams->thread, create_thread_node(( thread_t)
    {new_uuid, user_uuid, use_channel_uuid, command[1], command[2], new_time}));
    teams->comment = push_begin(teams->comment, create_comment_node((comment_t){
    generate_uuid(), user_uuid, new_uuid, command[2], new_time}));
    server_event_thread_created(use_channel_uuid, new_uuid,
    user_uuid, command[1], command[2]);
    dprintf(teams->clients[teams->iterator].socket, "152 %s~%s~%ld~%s~%s|\r\n",
    new_uuid, user_uuid, new_time, command[1], command[2]);
    send_event_message_to_team(teams, "994 %s~%s~%ld~%s~%s|\r\n",
    new_uuid, user_uuid, new_time, command[1], command[2]);
    return 0;
}
