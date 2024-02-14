/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** write_data_2.c
*/

#include "../../include/struct.h"
#include "../../include/teams.h"

void print_user_into_file(node_t *user_list, int file, char *filename)
{
    user_t *user;
    node_t *node = user_list;

    dprintf(file, "##user\n");
    while (node != NULL) {
        user = node->data;
        dprintf(file, "%s~%s\n", user->username, user->uuid);
        node = node->next;
    }
}

void print_team_into_file(node_t *team_list, int file, char *filename)
{
    team_t *team;
    uuid_users_t *uuid_users;
    node_t *buff_uuid_team;
    node_t *buff = team_list;

    dprintf(file, "##team\n");
    while (buff != NULL) {
        team = buff->data;
        dprintf(file, "%s~", team->uuid);buff_uuid_team = team->uuid_users;
        if (buff_uuid_team == NULL) dprintf(file, "#~");
        while (buff_uuid_team != NULL) {
            uuid_users = buff_uuid_team->data;
            buff_uuid_team->next == NULL ?
                dprintf(file, "%s~", uuid_users->uuid) :
                dprintf(file, "%s#", uuid_users->uuid);
            buff_uuid_team = buff_uuid_team->next;
        }
        dprintf(file, "%s~%s\n", team->name, team->description);
        buff = buff->next;
    }
}

void print_private_message_into_file(node_t *pm_list, int file, char *filename)
{
    private_message_t *pm;
    node_t *buff = pm_list;

    dprintf(file, "##privatemessage\n");
    while (buff != NULL) {
        pm = buff->data;
        dprintf(file, "%s~%s~%s~%ld~%s\n", pm->uuid, pm->uuid_receiver,
        pm->uuid_sender, pm->message_timestamp, pm->message);
        buff = buff->next;
    }
}
