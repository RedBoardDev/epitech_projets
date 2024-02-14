/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** read_saved_data.c
*/

#include "../../include/struct.h"
#include "../../include/teams.h"

int get_data_from_line(teams_t *teams, int *type, char *line)
{
    if (strstr(line, "##team")) {
        *type = LOGT_TEAM;
        return 1;
    }if (strstr(line, "##user")) {
        *type = LOGT_USER;
        return 1;
    }if (strstr(line, "##channel")) {
        *type = LOGT_CHANNEL;
        return 1;
    }if (strstr(line, "##thread")) {
        *type = LOGT_THREAD;
        return 1;
    }if (strstr(line, "##comment")) {
        *type = LOGT_COMMENT;
        return 1;
    }if (strstr(line, "##privatemessage")) {
        *type = LOGT_PRIVATE_MESSAGE;
        return 1;
    }return 0;
}

void put_data_on_linked_list(teams_t *teams, int type, char *line)
{
    if (LOGT_USER == type) {
        split_user_data(line, teams);
        return;
    }if (LOGT_TEAM == type) {
        split_team_data(strdup(line), teams);
        return;
    }if (LOGT_CHANNEL == type) {
        split_channel_data(line, teams);
        return;
    }if (LOGT_THREAD == type) {
        split_thread_data(line, teams);
        return;
    }if (LOGT_COMMENT == type) {
        split_comment_data(line, teams);
        return;
    }if (LOGT_PRIVATE_MESSAGE == type) {
        split_private_message_data(line, teams);
        return;
    }
}

int read_saved_data(teams_t *teams, char *filename)
{
    int type;
    FILE *f = fopen(filename, "r");
    ssize_t read = 0;
    size_t len = 0;
    char *line = NULL;
    if (f == NULL)
        exit (100);
    while ((read = getline(&line, &len, f)) != -1) {
        if (get_data_from_line(teams, &type, line) == 0)
            put_data_on_linked_list(teams, type, line);
    }
    fclose(f);
    free(line);
    return 0;
}
