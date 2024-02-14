/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** get_data_2.c
*/

#include "../../include/struct.h"
#include "../../include/teams.h"

static void split_array_uuid(char *str, team_t *team)
{
    int j = 0;
    uuid_users_t *uuid_userss;
    team->uuid_users = NULL;
    if (str[0] == '#') return;
    char *res = strtok(str, ",");
    for (; res[j] != '\0'; ++j);
    for (j = 0; res != NULL && res[j] != '\0'; ++j) {
        uuid_userss = malloc(sizeof(uuid_users_t));
        uuid_userss->uuid = strdup(res);
        team->uuid_users = push_begin(team->uuid_users, uuid_userss);
        res = strtok(NULL, ",");
    }
    free(str);
}

void split_team_data(char *str, teams_t *teams)
{
    team_t *team = (team_t *)malloc(sizeof(team_t));
    int nb = 0;for (; str[nb] != '\0'; ++nb);
    char **array = malloc(sizeof(char *) * (nb + 1));
    char *dup = strdup(str);char *tok = strtok(dup, "~");int index = 0;
    for (;tok != NULL; ++index) {
        array[index] = strdup(tok);
        tok = strtok(NULL, "~");
    }
    array[index] = NULL;
    for (int i = 0; array[i] != NULL; ++i) {
        if (i == 0)team->uuid = strdup(array[i]);
        if (i == 1)split_array_uuid(strdup(array[i]), team);
        if (i == 2)
            team->name = strdup(array[i]);
        if (i == 3) {
            array[i][strlen(array[i]) - 1] = '\0';
            team->description = strdup(array[i]);
        }
    }for (int i = 0; array[i] != NULL; ++i)free(array[i]);
    teams->team = push_begin(teams->team, team);
}

void split_private_message_data(char *str, teams_t *teams)
{
    char *tok = strtok(str, "~");
    private_message_t *private_message = malloc(sizeof(private_message_t));

    for (int i = 0; tok != NULL; ++i) {
        if (i == 0)
            private_message->uuid = strdup(tok);
        if (i == 1)
            private_message->uuid_receiver = strdup(tok);
        if (i == 2)
            private_message->uuid_sender = strdup(tok);
        if (i == 3)
            private_message->message_timestamp = atoi(tok);
        if (i == 4) {
            tok[strlen(tok) - 1] = '\0';
            private_message->message = strdup(tok);
        }
        tok = strtok(NULL, "~");
    }
    teams->private_message =
    push_begin(teams->private_message, private_message);
}
