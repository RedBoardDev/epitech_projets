/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** messages.c
*/

#include "../../include/teams.h"

void cmd_messages(teams_t *teams, char **command, int nbr_args)
{
    private_message_t *current;
    node_t *current_node = teams->private_message;
    user_t *current_user = get_user_by_uuid(teams->user, command[1]);
    char *ret = malloc(sizeof(char) * 1);memset(ret, 0, 1);char tmp[50];

    if (current_user == NULL)
        dprintf(teams->clients[teams->iterator].socket, "331 failed\r\n");
    while (current_node != NULL) {
        current = current_node->data;
        if (strcmp(current->uuid_receiver, command[1]) == 0 ||
        strcmp(current->uuid_sender, command[1]) == 0) {
            ret = my_strcat(ret, current->uuid_sender);
            ret = my_strcat(ret, "~");
            sprintf(tmp, "%ld", current->message_timestamp);
            ret = my_strcat(ret, tmp);ret = my_strcat(ret, "~");
            ret = my_strcat(ret, current->message);ret = my_strcat(ret, "|");
        }
        current_node = current_node->next;
    }
    dprintf(teams->clients[teams->iterator].socket, "131 %s\r\n", ret);
}
